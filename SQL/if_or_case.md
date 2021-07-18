## Reference
1. case ..
2. if ..


## 프로그래머스 | String, Date | 이름에 el이 들어가는 동물 찾기

### 문제 설명

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다.

|NAME|	TYPE|	NULLABLE|
| :--:| :--:| :--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME|	VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME|	VARCHAR(N)	|FALSE|

**보호소의 동물이 중성화되었는지 아닌지 파악하려 합니다. 중성화된 동물은 SEX_UPON_INTAKE 컬럼에 'Neutered' 또는 'Spayed'라는 단어가 들어있습니다. 동물의 아이디와 이름, 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성해주세요. 이때 중성화가 되어있다면 'O', 아니라면 'X'라고 표시해주세요.**

### 예시
예를 들어 ANIMAL_INS 테이블이 다음과 같다면

|ANIMAL_ID|	ANIMAL_TYPE|	|DATETIME	|INTAKE_CONDITION	|NAME	SEX_UPON_INTAKE|
|:--:|:--:|:--:|:--:|:--:|:--:|
|A355753|	Dog|	|2015-09-10 13:14:00	|Normal	|Elijah	|Neutered Male|
|A373219|	Cat|	|2014-07-29 11:43:00	|Normal |Ella	|Spayed Female|
|A382192|	Dog|	|2015-03-13 13:14:00|	Normal	|Maxwell 2	|Intact Male|

- 중성화한 동물: Elijah, Ella
- 중성화하지 않은 동물: Maxwell 2
- 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_ID	|NAME	|중성화|
|:--:|:--:|:--:|
|A355753|Elijah	|O|
|A373219|Ella	|O|
|A382192|Maxwell 2	|X|

※ 컬럼 이름은 일치하지 않아도 됩니다.
>본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
1. 임의로 컬럼을 생성하여 결과값을 만들어내는 문제다.

2. 데이터 테이블을 직접적으로 수정하는 `ALTER`을 사용하지 않고(SQL 테스트는 DDL을 지원하지 않는다), 1회성 집계를 위해 `IF` 혹은 `case` 를 사용해 문제를 해결해야 한다.

3. 문자열 일부를 검사하는 `LIKE` 구문을 활용해야 한다.

