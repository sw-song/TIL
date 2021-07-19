
## 프로그래머스 | 2021 Dev-Matching: 웹 백엔드 개발자(상반기) | 헤비 유저가 소유한 장소

### 문제 설명

`PLACES` 테이블은 공간 임대 서비스에 등록된 공간의 정보를 담은 테이블입니다. `PLACES` 테이블의 구조는 다음과 같으며 `ID`, `NAME`, `HOST_ID`는 각각 공간의 아이디, 이름, 공간을 소유한 유저의 아이디를 나타냅니다. `ID`는 기본키입니다.

|NAME|	TYPE|
|:--:|:--:|
|ID|	INT|
|NAME|	VARCHAR|
|HOST_ID|	INT|

### 문제
**이 서비스에서는 공간을 둘 이상 등록한 사람을 "헤비 유저"라고 부릅니다. 헤비 유저가 등록한 공간의 정보를 아이디 순으로 조회하는 SQL문을 작성해주세요.**

### 예시

예를 들어, PLACES 테이블이 다음과 같다면

|ID|	NAME|	HOST_ID|
|:--:|:--:|:--:|
|4431977	|BOUTIQUE STAYS - Somerset Terrace, Pet Friendly|	760849|
|5194998	|BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly|	760849|
|16045624	|Urban Jungle in the Heart of Melbourne	|30900122|
|17810814	|Stylish Bayside Retreat with a Luscious Garden|	760849|
|22740286	|FREE PARKING - The Velvet Lux in Melbourne CBD|	30900122|
|22868779	|★ Fresh Fitzroy Pad with City Views! ★	|21058208|

- 760849번 유저는 공간을 3개 등록했으므로 이 유저는 헤비유저입니다.
- 30900122번 유저는 공간을 2개 등록했으므로 이 유저는 헤비유저입니다.
- 21058208번 유저는 공간을 1개 등록했으므로 이 유저는 헤비유저가 아닙니다.

따라서 SQL 문을 실행하면 다음과 같이 나와야 합니다.

|ID|	NAME|	HOST_ID|
|:--:|:--:|:--:|
|4431977|	BOUTIQUE STAYS - Somerset Terrace, Pet Friendly	|760849|
|5194998|	BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly	|760849|
|16045624|	Urban Jungle in the Heart of Melbourne	|30900122|
|17810814|	Stylish Bayside Retreat with a Luscious Garden|	760849|
|22740286|	FREE PARKING - The Velvet Lux in Melbourne CBD|	30900122|

---

1. 둘 이상의 공간을 계약한 `HOST_ID`를 찾고, 해당 `HOST_ID`가 계약한 정보(`ID`, `NAME`, `HOST_ID`)를 가져오면 되는 문제다.

2. 주의해야 할 점은 "둘 이상의 공간을 계약한 `HOST_ID`를 찾고"에서 그치면 안 된다는 것. 예를 들면,

```SQL
SELECT ID, NAME, HOST_ID FROM PLACES
GROUP BY HOST_ID
HAVING COUNT(HOST_ID) >= 2
```

|ID|	NAME|	HOST_ID|
|:--:|:--:|:--:|
|4431977|	BOUTIQUE STAYS - Somerset Terrace, Pet Friendly|	760849|
|16045624|	Urban Jungle in the Heart of Melbourne|	30900122|

- `GROUP BY`로 집계했기 때문에 순서상 빠른 데이터 1개씩만 가져온다.

3. 해당 `HOST_ID`로 계약한 내용을 모두 불러오기 위해서는 재차 질의를 해야 한다.
```SQL
SELECT ID, NAME, HOST_ID FROM PLACES
WHERE HOST_ID IN (
    SELECT HOST_ID FROM PLACES
    GROUP BY HOST_ID
    HAVING COUNT(HOST_ID) >= 2)
```

|ID|	NAME	|HOST_ID|
|:-:|:-:|:-:|
|4431977|	BOUTIQUE STAYS - Somerset Terrace, Pet Friendly|	760849|
|5194998|	BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly|	760849|
|16045624|	Urban Jungle in the Heart of Melbourne|	30900122|
|17810814|	Stylish Bayside Retreat with a Luscious Garden|	760849|
|22740286|	FREE PARKING - The Velvet Lux in Melbourne CBD|	30900122|

4. 만약 subquery를 사용하지 않는다면 아래와 같이 테이블을 복제하여 비교하는 방법도 있다. 단, 아래와 같이 중복 집계가 될 수 있으니 유의해야 한다.

```SQL
SELECT A.ID, A.NAME, A.HOST_ID FROM PLACES A, PLACES B
WHERE A.ID != B.ID 
  AND A.HOST_ID = B.HOST_ID
ORDER BY A.ID
```

|ID|	NAME	|HOST_ID|
|:-:|:--:|:--:|
|4431977|	BOUTIQUE STAYS - Somerset Terrace, Pet Friendly	|760849|
|4431977|	BOUTIQUE STAYS - Somerset Terrace, Pet Friendly	|760849|
|5194998|	BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly	|760849|
|5194998|	BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly	|760849|
|16045624|	Urban Jungle in the Heart of Melbourne	|30900122|
|17810814|	Stylish Bayside Retreat with a Luscious Garden	|760849|
|17810814|	Stylish Bayside Retreat with a Luscious Garden	|760849|
|22740286|	FREE PARKING - The Velvet Lux in Melbourne CBD	|30900122|

- JOIN을 사용하지 않고 테이블을 결합했기 때문에 3개 이상의 공간을 계약한 경우 이렇게 중복 값이 들어갈 수 있다.

5. `DISTINCT`를 통해 중복을 제거할 수 있다.

```SQL
SELECT DISTINCT A.ID, A.NAME, A.HOST_ID FROM PLACES A, PLACES B
WHERE A.ID != B.ID 
  AND A.HOST_ID = B.HOST_ID
ORDER BY A.ID
```
|ID	|NAME	|HOST_ID|
|:-:|:--:|:--:|
|4431977	|BOUTIQUE STAYS - Somerset Terrace, Pet Friendly	|760849|
|5194998	|BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly	|760849|
|16045624	|Urban Jungle in the Heart of Melbourne	|30900122|
|17810814	|Stylish Bayside Retreat with a Luscious Garden	|760849|
|22740286	|FREE PARKING - The Velvet Lux in Melbourne CBD	|30900122|


6. 물론 JOIN을 사용할 수도 있다. 단, 동일하게 `DISTINCT`로 중복을 제거해줘야 한다.

```SQL
SELECT DISTINCT A.ID, A.NAME, A.HOST_ID FROM PLACES A
JOIN PLACES B ON A.HOST_ID = B.HOST_ID
WHERE A.ID != B.ID
ORDER BY A.ID
```
|ID	|NAME	|HOST_ID|
|:-:|:--:|:--:|
|4431977	|BOUTIQUE STAYS - Somerset Terrace, Pet Friendly	|760849|
|5194998	|BOUTIQUE STAYS - Elwood Beaches 3, Pet Friendly	|760849|
|16045624	|Urban Jungle in the Heart of Melbourne	|30900122|
|17810814	|Stylish Bayside Retreat with a Luscious Garden	|760849|
|22740286	|FREE PARKING - The Velvet Lux in Melbourne CBD	|30900122|

