## Reference
1. [stackoverflow / Replace nulls values in sql using select statement in mysql?](https://stackoverflow.com/questions/9877533/replace-nulls-values-in-sql-using-select-statement-in-mysql)

---

## 프로그래머스 | IS NULL | NULL 처리하기

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

입양 게시판에 동물 정보를 게시하려 합니다. 동물의 생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성해주세요. 이때 프로그래밍을 모르는 사람들은 NULL이라는 기호를 모르기 때문에, 이름이 없는 동물의 이름은 "No name"으로 표시해 주세요.

### 예시

예를 들어 ANIMAL_INS 테이블이 다음과 같다면

|ANIMAL_ID	|ANIMAL_TYPE|	DATETIME	|INTAKE_CONDITION	|NAME|	SEX_UPON_INTAKE|
|:------:|:------:|:------:|:------:|:------:|:------:|
|A350276	|Cat	|2017-08-13 13:50:00	|Normal	    |Jewel	|Spayed Female|
|A350375	|Cat	|2017-03-06 15:01:00	|Normal   	|Meo	|Neutered Male|
|A368930	|Dog	|2014-06-08 13:20:00	|Normal	     |NULL	|Spayed Female|

마지막 줄의 개는 이름이 없기 때문에, 이 개의 이름은 "No name"으로 표시합니다. 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_TYPE	|NAME|	SEX_UPON_INTAKE|
|:------:|:------:|:------:|
|Cat	|Jewel	|Spayed Female|
|Cat	|Meo	|Neutered Male|
|Dog	|No name|	Spayed Female|

※ 컬럼 이름은 일치하지 않아도 됩니다.

> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
1. 만약 문제가 단순히 "NAME이 공란이면 제외하라" 였다면 아래와 같이 쿼리를 작성할 수 있다.
```SQL
SELECT ANIMAL_TYPE, NAME, SEX_UPON_INTAKE FROM ANIMAL_INS
WHERE NAME IS NULL
```

2. 그러나 문제는 "NAME이 공란이면 NULL은 'No name'으로 채워넣어라" 라는 조건을 포함하기 때문에 `SELECT`와 함께 IFNULL 함수를 조건으로 걸어줄 수 있겠다.
```SQL
SELECT ANIMAL_TYPE, IFNULL(NAME,'No name') as NAME, SEX_UPON_INTAKE FROM ANIMAL_INS
```

3. 물론 컬럼 이름은 일치하지 않아도 된다는 설명이 있으므로 `NAME` alias를 별도로 지정하지 않아도 좋다.
```SQL
SELECT ANIMAL_TYPE, IFNULL(NAME,'No name'), SEX_UPON_INTAKE FROM ANIMAL_INS
```

4. MySQL에서 `NULL`을 문자로 채워넣을 수 있는 방법은 몇 가지 더 있다.
- 4-1. 해당 문제에서 인자를 2개만 넣는 경우에 한해, `IFNULL`과 동일한 역할을 해주는 `COALESCE`를 사용한다.
```SQL
SELECT ANIMAL_TYPE, COALESCE(NAME,'No name'), SEX_UPON_INTAKE FROM ANIMAL_INS
```
> `COALESCE` 함수는 표준 SQL 문법으로, 배타적 OR 관계 열(관계 열 내의 모든 행에서 하나씩 값이 존재, 나머지는 NULL)에서 사용할 수도 있다. 아래 쿼리를 실행하면 3개의 컬럼 중 값이 존재하는 부분만 가져올 수 있다.
```SQL
SELECT COALESCE(column1, column2, column3) FROM SAMPLETABLE
```
- 4-2. CASE 문을 사용한다.
```SQL
SELECT 
    ANIMAL_TYPE, -- Column 1
    CASE -- Column 2
    WHEN NAME IS NULL THEN "No name" -- NAME이 NULL이면 "No name"을 반환한다
    ELSE NAME END AS NAME -- NALL이 NULL이 아니면(값이 존재하면) 그 값을 그대로 반환한다.
    ,
    SEX_UPON_INTAKE -- Column 3
FROM ANIMAL_INS
```
> CASE 문만 따로 보면 아래와 같다.
```SQL
SELECT CASE
    WHEN NAME IS NULL THEN "No name" -- NAME이 NULL이면 "No name"을 반환한다
    ELSE NAME END AS NAME -- NALL이 NULL이 아니면(값이 존재하면) 그 값을 그대로 반환한다.
FROM ANIMAL_INS
```