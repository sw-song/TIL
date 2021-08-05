## Reference
1. [Unknown column in Having Clause](https://dba.stackexchange.com/questions/275399/unknown-column-in-having-clause)
---

## 프로그래머스 | GROUP BY | 입양 시각 구하기(1)

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 09:00부터 19:59까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 이때 결과는 시간대 순으로 정렬해야 합니다.

### 예시
SQL문을 실행하면 다음과 같이 나와야 합니다.

|HOUR	|COUNT|
| :--:| :--:|
|9|	1|
|10|	2|
|11|	13|
|12|	10|
|13|	14|
|14	|9|
|15	|7|
|16	|10|
|17	|12|
|18	|16|
|19	|2|

본 문제는 [Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
`GROUP BY`와 함께 조건(`HAVING`)절을 적절히 사용할 수 있는지 묻는 문제다.

특히, 데이터를 group by하고 `SELECT`를 통해 집계하면, 데이터테이블은 완전히 다른 정보를 갖게 된다. 여기서 `HAVING`으로 달라진 정보를 바뀐 열 이름으로 가져올 수 있어야 한다.

1. 쿼리는 아래와 같이 작성할 수 있다.

```SQL
SELECT hour(datetime) as h, count(hour(datetime)) as c FROM ANIMAL_OUTS
GROUP BY hour(datetime)
HAVING h >= 9 AND h < 20
ORDER BY h
```

|h|	c|
|:-:|:-:|
|9|	1|
|10|	2|
|11|	13|
|12|	10|
|13|	14|
|14|	9|
|15|	7|
|16|	10|
|17|	12|
|18|	16|
|19|	2|


주의해야 할 점은 위와 같이 기존에 존재하던 열(datetime)이 `SELECT` 집계를 사용함으로써 이제는 존재하지 않기 때문에`HAVING` 절에서 datetime을 불러내면 에러가 난다는 것이다.

**(에러 메시지 예시)**
> Unknown column 'datetime' in 'having clause'

`ORDER BY` 에서는 hour(datetime)을 가져올 수 있지만 `HAVING`을 통해서 hour(datetime)을 가져오는 것은 불가능하다. 실수가 잦은 부분이므로 alias를 적절히 잘 사용하는 것이 중요하다.

