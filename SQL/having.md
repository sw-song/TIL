### reference :
1. [SQL WHERE과 HAVING의 차이](http://growthj.link/sql-where과-having의-차이/)

---

## 프로그래머스 | GROUP BY | 동명 동물 수 찾기

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

동물 보호소에 들어온 동물 이름 중 두 번 이상 쓰인 이름과 해당 이름이 쓰인 횟수를 조회하는 SQL문을 작성해주세요. 이때 결과는 이름이 없는 동물은 집계에서 제외하며, 결과는 이름 순으로 조회해주세요.

### 예시

예를 들어 ANIMAL_INS 테이블이 다음과 같다면

|ANIMAL_ID	|ANIMAL_TYPE|	DATETIME	|INTAKE_CONDITION	|NAME|	SEX_UPON_INTAKE|
|:------:|:------:|:------:|:------:|:------:|:------:|
|A396810|	Dog|	2016-08-22 16:13:00|	Injured|	Raven|	Spayed Female
|A377750|	Dog|	2017-10-25 17:17:00|	Normal|	Lucy	|Spayed Female
|A355688|	Dog|	2014-01-26 13:48:00|	Normal|	Shadow	|Neutered Male
|A399421|	Dog|	2015-08-25 14:08:00|	Normal|	Lucy	|Spayed Female
|A400680|	Dog|	2017-06-17 13:29:00|	Normal|	Lucy	|Spayed Female
|A410668|	Cat|	2015-11-19 13:41:00|	Normal|	Raven	|Spayed Female

- Raven 이름은 2번 쓰였습니다.
- Lucy 이름은 3번 쓰였습니다
- Shadow 이름은 1번 쓰였습니다.

따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|NAME|	COUNT|
|:--:|:-----:|
|Lucy|	3|
|Raven|	2|


> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
1. group by와 함께 적절한 조건절을 사용할 수 있는지 확인하는 문제다.

`WHERE`은 항상 `FROM` 바로 뒤에 위치하며, `GROUP BY` 앞에 위치한다.
`GROUP BY`와 함께 사용하는 경우 주의해야 할 점은 `GROUP BY` 절을 통해 group by된 데이터에 `WHERE`을 사용할 수 없다는 점이다.

만약 group by된 데이터에 조건을 걸고 싶다면, `HAVING`을 사용하면 된다.

`HAVING`은 항상 `GROUP BY` 뒤에 위치하고, `WHERE` 처럼 조건절 역할을 한다. 다만, group by된 데이터에만 사용할 수 있다.

2. 답안은 아래와 같이 작성해볼 수 있다.

```sql
SELECT name, count(name) FROM animal_ins
GROUP BY name
HAVING count(name) >= 2
ORDER BY name
```

|name	|count(name)|
|:-----:|:---------:|
|Lucy	|3|
|Raven	|2|

