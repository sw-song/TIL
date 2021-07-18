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

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다. ANIMAL_OUTS 테이블의 ANIMAL_ID는 ANIMAL_INS의 ANIMAL_ID의 외래 키입니다.

|NAME|	TYPE|	NULLABLE|
|:--:|:--:|:--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME	|VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME	|VARCHAR(N)	|FALSE|

관리자의 실수로 일부 동물의 입양일이 잘못 입력되었습니다. 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 이때 결과는 보호 시작일이 빠른 순으로 조회해야합니다.

### 예시
예를 들어, ANIMAL_INS 테이블과 ANIMAL_OUTS 테이블이 다음과 같다면

> ANIMAL_INS

|ANIMAL_ID	|ANIMAL_TYPE|	DATETIME	|INTAKE_CONDITION	|NAME	|SEX_UPON_INTAKE|
|:--:|:--:|:--:|:--:|:--:|:--:|
|A350276	|Cat|	2017-08-13 13:50:00	|Normal	|Jewel	|Spayed Female|
|A381217	|Dog|	2017-07-08 09:41:00	|Sick|	Cherokee	|Neutered Male|

> ANIMAL_OUTS

|ANIMAL_ID	|ANIMAL_TYPE|	DATETIME	|NAME|	SEX_UPON_OUTCOME|
|:--:|:--:|:--:|:--:|:--:|
|A350276	|Cat|	2018-01-28 17:51:00	|Jewel	|Spayed Female|
|A381217	|Dog|	2017-06-09 18:51:00	|Cherokee	|Neutered Male|

SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_ID	|NAME|
|:--:|:--:|
|A381217	|Cherokee|

> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
1. 양쪽 TABLE의 DATETIME 값을 비교하는 문제이다.

2. `ANIMAL_INS`의 `DATETIME`이 `ANIMAL_OUTS`의 `DATETIME`보다 크다면(시간상 늦다면) 데이터가 잘못 입력된 것이다. 이렇게 잘못 입력된 열을 찾아내는 것이 본 문제의 요구 사항이다.

3. 두 테이블을 비교하기 위해 우선 `INNER JOIN`을 사용한다. 두 테이블에 동일한 `ANIMAL_ID`가 존재해야 양 쪽의 `DATETIME`을 비교할 수 있기 때문에 교집합을 추출하는 것이다.

4. `JOIN`을 했다면 `WHERE` 로 간단히 비교하면 된다. 풀이는 아래와 같다.

```SQL
SELECT I.ANIMAL_ID, I.NAME FROM ANIMAL_INS I
JOIN ANIMAL_OUTS O I.ANIMAL_ID = O.ANIMAL_ID -- ANIMAL_ID 기준 교집합 집계
WHERE I.DATETIME > O.DATETIME -- DATETIME 비교
ORDER BY I.DATETIME -- 문제에서 시간순 정렬 요구
```

|ANIMAL_ID|	NAME|
|:--:|:--:|
|A362383	|*Morado|
|A381217|	Cherokee|

5. `JOIN`을 사용하지 않는다면 아래와 같이 작성할 수 있다.
- 참고 : [프로그래머스 | mysql join 사용하지 않은 정답 공유 | 박현수](https://programmers.co.kr/questions/16249)

```SQL
SELECT I.ANIMAL_ID, I.NAME 
FROM ANIMAL_INS I, ANIMAL_OUTS O
WHERE I.ANIMAL_ID = O.ANIMAL_ID
  AND I.DATETIME > O.DATETIME
ORDER BY I.DATETIME
```

|ANIMAL_ID|	NAME|
|:--:|:--:|
|A362383	|*Morado|
|A381217|	Cherokee|


