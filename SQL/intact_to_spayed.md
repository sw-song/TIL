## 프로그래머스 | JOIN | 보호소에서 중성화한 동물

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다. ANIMAL_OUTS 테이블의 ANIMAL_ID는 ANIMAL_INS의 ANIMAL_ID의 외래 키입니다.

|NAME|	TYPE|	NULLABLE|
|:--:|:--:|:--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME	|VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME	|VARCHAR(N)	|FALSE|

**보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 보호소에 들어올 당시에는 중성화1되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.**

### 예시
예를 들어, ANIMAL_INS 테이블과 ANIMAL_OUTS 테이블이 다음과 같다면

> ANIMAL_INS

|ANIMAL_ID|	ANIMAL_TYPE	|DATETIME	|INTAKE_CONDITION	|NAME	|SEX_UPON_INTAKE|
|:--:|:--:|:--:|:--:|:--:|:--:|
|A367438|	Dog|	2015-09-10 16:01:00	|Normal	|Cookie	|Spayed Female|
|A382192|	Dog|	2015-03-13 13:14:00	|Normal	|Maxwell |2	|Intact Male|
|A405494|	Dog|	2014-05-16 14:17:00	|Normal	|Kaila	|Spayed Female|
|A410330|	Dog|	2016-09-11 14:09:00	|Sick	|Chewy	|Intact Female|

> ANIMAL_OUTS

|ANIMAL_ID|	ANIMAL_TYPE|	DATETIME	|NAME	|SEX_UPON_OUTCOME|
|:--:|:--:|:--:|:--:|:--:|
|A367438|	Dog|	2015-09-12 13:30:00	|Cookie	|Spayed Female|
|A382192|	Dog|	2015-03-16 13:46:00	|Maxwell 2	|Neutered Male|
|A405494|	Dog|	2014-05-20 11:44:00	|Kaila	|Spayed Female|
|A410330|	Dog|	2016-09-13 13:46:00	|Chewy	|Spayed Female|

- Cookie는 보호소에 들어올 당시에 이미 중성화되어있었습니다.
- Maxwell 2는 보호소에 들어온 후 중성화되었습니다.
- Kaila는 보호소에 들어올 당시에 이미 중성화되어있었습니다.
- Chewy는 보호소에 들어온 후 중성화되었습니다.
- 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_ID|	ANIMAL_TYPE|	NAME|
|:--:|:--:|:--:|
|A382192|	Dog|	Maxwell 2|
|A410330|	Dog|	Chewy|

> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

**+중성화를 거치지 않은 동물은 성별 및 중성화 여부에 Intact, 중성화를 거친 동물은 Spayed 또는 Neutered라고 표시되어있습니다.**

---
1. `ANIMAL_INS` 테이블의 `SEX_UPON_INTAKE`는 'Intact %', `ANIMAL_OUTS` 테이블의 `SEX_UPON_OUTCOME`은 'Spayed %' 혹은 'Neutered %'인 행을 집계하는 문제다.

2. `WHERE` 절 조건연산자를 2개 동시에 사용해야 한다. 괄호를 통해 영역구분을 잘 해주지 않으면 집계 값이 완전히 달라지니 유의해야 한다.

3. `JOIN`을 사용하지 않아도 되는 간단한 집계다. 아래와 같이 서브쿼리로 작성해 볼 수 있다.

```SQL
SELECT ANIMAL_ID, ANIMAL_TYPE, NAME FROM ANIMAL_OUTS
WHERE (
      SEX_UPON_OUTCOME LIKE 'SPAYED%'
      OR 
      SEX_UPON_OUTCOME LIKE 'NEUTERED%'
      ) -- 중성화된 동물만 집계
  AND ANIMAL_ID IN ( 
      SELECT ANIMAL_ID FROM ANIMAL_INS 
      WHERE SEX_UPON_INTAKE LIKE 'Intact%'
  ) -- 보호소 당시 중성화 하지 않은 동물만 집계
ORDER BY ANIMAL_ID, ANIMAL_TYPE, NAME
```

|ANIMAL_ID	|ANIMAL_TYPE|	NAME|
|:--:|:--:|:--:|
|A382192	|Dog	|Maxwell 2|
|A410330	|Dog	|Chewy|

4. `JOIN` 사용할 수도 있다.

```SQL
SELECT O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME FROM ANIMAL_OUTS O
JOIN ANIMAL_INS I ON O.ANIMAL_ID = I.ANIMAL_ID
WHERE (
      O.SEX_UPON_OUTCOME LIKE 'SPAYED%'
      OR 
      O.SEX_UPON_OUTCOME LIKE 'NEUTERED%'
      ) -- 입양 당시 중성화 O
  AND I.SEX_UPON_INTAKE LIKE 'Intact%' -- 보호소 당시 중성화 X
ORDER BY O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME
```

