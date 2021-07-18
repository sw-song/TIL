## Reference
1. [[SQL] Recursive 표현으로 쿼리 만들기](https://velog.io/@cyanred9/SQL-Recursive)
2. [A Definitive Guide To MySQL Recursive CTE](https://www.mysqltutorial.org/mysql-recursive-cte/)
3. [[Postgresql] recursive 문이란? 개념 및 예제](https://sas-study.tistory.com/165)

---

## 프로그래머스 | GROUP BY | 입양 시각 구하기(2)

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 0시부터 23시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 이때 결과는 시간대 순으로 정렬해야 합니다.
예시
SQL문을 실행하면 다음과 같이 나와야 합니다.

|HOUR	|COUNT|
| :--:| :--:|
|0|	0|
|1|	0|
|2|	0|
|3|	0|
|4|	0|
|5|	0|
|6|	0|
|7|	3|
|8|	1|
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
|20	|0|
|21	|0|
|22|	0|
|23|	0|

본 문제는 [Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---

추출해야 할 행은 HOUR(1시간 간격 시간대, 총 24시간), count(HOUR)이다.
제공된 데이터셋만 활용해서는 전체 시간대(총 24시간)를 불러올 수 없으며, 임의로 0부터 23까지의 값을 가지는 행을 생성한 다음 해당 행을 Key로 `LEFT JOIN(OUTER JOIN)`해야 한다.

> SQL에서 반복문은 아래와 같이 동작시킬 수 있다.
1. `RECURSIVE`로 반복을 시작한다.
2. `UNION ALL`으로 반복을 수행하며 row를 붙여나간다. (행의 합집합)
3. `WHERE`로 반복문을 빠져나갈 조건을 만든다.

```SQL
WITH RECURSIVE CTE as ( -- 반복문 시작
    SELECT 0 as HOUR -- HOUR 컬럼을 생성하고 0을 최초로 담는다.
    UNION ALL -- 모든 행을 unique하게 결합한다.(합집합)
    SELECT HOUR+1 FROM CTE  -- HOUR 컬럼에 계속해서 1씩 늘려가며 열을 추가한다.
    WHERE HOUR < 23 -- 23회 반복
)
SELECT c.HOUR, count(hour(o.datetime)) as COUNT FROM CTE as c
LEFT JOIN ANIMAL_OUTS as o ON c.HOUR = hour(o.datetime)
GROUP BY c.HOUR
```
|HOUR|	COUNT|
|:--:|:--:|
|0|	0|
|1|	0|
|2|	0|
|3|	0|
|4|	0|
|5|	0|
|6|	0|
|7|	3|
|8|	1|
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
|20|	0|
|21|	0|
|22|	0|
|23|	0|
