## Reference 
1. [SQL 중복 제거 - select distinct 사용법](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=50after&logNo=220939090572)
2. [[MYSQL]GROUP BY, HAVING](https://victorydntmd.tistory.com/138)
3. [[SQL]WITH절 사용하기](https://royzero.tistory.com/50)

---

## 프로그래머스 | Summer/Winter Coding(2019) | 우유와 요거트가 담긴 장바구니

### 문제 설명

`CART_PRODUCTS` 테이블은 장바구니에 담긴 상품 정보를 담은 테이블입니다. `CART_PRODUCTS` 테이블의 구조는 다음과 같으며, `ID`, `CART_ID`, `NAME`, `PRICE`는 각각 테이블의 아이디, 장바구니의 아이디, 상품 종류, 가격을 나타냅니다.

|NAME|	TYPE|
|:--:|:--:|
|ID|	INT|
|CART_ID|	INT|
|NAME|	VARCHAR|
|PRICE|	INT|

데이터 분석 팀에서는 우유(Milk)와 요거트(Yogurt)를 동시에 구입한 장바구니가 있는지 알아보려 합니다. 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회하는 SQL 문을 작성해주세요. 이때 결과는 장바구니의 아이디 순으로 나와야 합니다.

### 예시

예를 들어 `CART_PRODUCTS` 테이블이 다음과 같다면

> CART_PRODUCTS 테이블

|ID|	CART_ID|	NAME|	PRICE|
|:-:|:---:|:--:|:--:|
|1630|	83|	Cereal|	3980|
|1631|	83|	Multipurpose Supply|3900|
|5491|	286|	Yogurt|	2980|
|5504|	286|	Milk|	1880|
|8435|	448|	Milk|	1880|
|8437|	448|	Yogurt|	2980|
|8438|	448|	Tea|	11000|
|20236|	1034|	Yogurt|	2980|
|20237|	1034|	Butter|	4890|

- 83번 장바구니에는 Milk와 Yogurt가 모두 없습니다.
- 286번 장바구니에는 Milk와 Yogurt가 모두 있습니다.
- 448번 장바구니에는 Milk와 Yogurt가 모두 있습니다.
- 1034번 장바구니에는 Milk는 없고 Yogurt만 있습니다.

따라서 SQL 문을 실행하면 다음과 같이 나와야 합니다.

|CART_ID|
|:--:|
|286|
|448|

---
1. 하나의 데이터 테이블에서 동일 컬럼(NAME)에 대해 2가지 서로 다른 값을 동시에 가지고 있는 ID를 찾는 문제다.

2. `Yogurt`와 `Milk`를 각각 카운트하여 `IF` 절을 통해 집계하고 2개 이상 카운트된 장바구니를 찾으면 될 것 같다.

```SQL
SELECT CART_ID FROM CART_PRODUCTS
GROUP BY CART_ID
HAVING SUM(IF(NAME IN ('Yogurt', 'Milk'),1,0)) >= 2
```

|CART_ID|
|:--:|
286
448
578
789
830
977
1048


3. 그러나 위 결과 값에는 `Yogurt`만 2번 담겨 있는 경우도 포함된다. `CART_ID` 789번을 보면 `Milk`를 구매하지 않았지만 

|ID|	CART_ID|	NAME|	PRICE
|:-:|:-:|:-:|:-:|
|15340|	789|	Snack|	2380
|15341|	789|	Laundry Care|	12900
|15342|	789|	Pasta|	1980
|15343|	789|	Vegetable|	2480
|15344|	789|	Pork|	8900
|15345|	789|	**Yogurt**|	2980
|15346|	789|	**Yogurt**|	2980
|15347|	789|	Flour|	1580
|15348|	789|	Fruit|	2980
|15349|	789|	Disposable Tableware|	1080
|15350|	789|	Disposable Tableware|	1080
|15351|	789|	Dish Detergent|	4900
|15352|	789|	Flour|	1580
|15353|	789|	Pork|	8900
|15354|	789|	Ice Cream|	3980

4. 집계 해보면 `COUNT`가 2건으로 나온다.
```SQL
SELECT CART_ID, SUM(IF(NAME IN ('Yogurt', 'Milk'),1,0)) AS CNT FROM CART_PRODUCTS
GROUP BY CART_ID
HAVING CNT >= 2
```

|CART_ID|	CNT|
|:--:|:--:|
|286|	2|
|448|	3|
|578|	3|
|**789**|	**2**|
|830|	3|
|977|	2|
|1048|	3|

5. 따라서 `SELECT DISTINCT`를 통해 먼저 UNIQUE한 `NAME`으로 집계된 임시 테이블을 새롭게 정의한 다음 해당 테이블에서 `GROUP BY`와 `HAVING`으로 `Yogurt`와 `Milk`를 카운트해야 한다.

```SQL
WITH t AS (
  SELECT DISTINCT CART_ID, NAME FROM CART_PRODUCTS
  WHERE NAME IN ('Yogurt', 'Milk')
)

SELECT CART_ID FROM t
GROUP BY CART_ID
HAVING SUM(IF(NAME IN ('Yogurt', 'Milk'),1,0)) >= 2
```

|CART_ID|
|:--:|
286
448
578
977
1048

6. 이렇게 임시 테이블을 생성하지 않는 경우 테이블을 복제하여 하나의 테이블에서는 `Milk`를 찾고, 다른 테이블에서는 `Yogurt`를 찾는 방식으로 시도해볼 수도 있다.

```SQL
SELECT A.CART_ID FROM CART_PRODUCTS A, CART_PRODUCTS B
WHERE A.CART_ID = B.CART_ID -- 같은 장바구니에서
  AND (A.NAME = 'Yogurt' AND B.NAME = 'Milk') -- Yorgurt와 Milk를 모두 구매
```

|CART_ID|
|:--:|
286
448
578
977
1048
