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

보호소에 돌아가신 할머니가 기르던 개를 찾는 사람이 찾아왔습니다. 이 사람이 말하길 할머니가 기르던 개는 이름에 'el'이 들어간다고 합니다. 동물 보호소에 들어온 동물 이름 중, 이름에 "EL"이 들어가는 개의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 이때 결과는 이름 순으로 조회해주세요. 단, 이름의 대소문자는 구분하지 않습니다.

### 예시
예를 들어 ANIMAL_INS 테이블이 다음과 같다면

|ANIMAL_ID|	ANIMAL_TYPE|	DATETIME	|INTAKE_CONDITION	|NAME	|SEX_UPON_INTAKE|
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|A355753  |	Dog        |2015-09-10 13:14:00|    Normal	|Elijah      |Neutered Male|
|A352872  |	Dog        |2015-07-09 17:51:00|    Aged	|Peanutbutter|Neutered Male|
|A353259  |	Dog        |2016-05-08 12:57:00|    Injured	|Bj          |Neutered Male|
|A373219  |	Cat        |2014-07-29 11:43:00|    Normal	|Ella	       |Spayed Female|
|A382192  |	Dog        |2015-03-13 13:14:00|    Normal	|Maxwell 2	   |Intact Male|


이름에 'el'이 들어가는 동물은 Elijah, Ella, Maxwell 2입니다.
이 중, 개는 Elijah, Maxwell 2입니다.
따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_ID|	NAME|
|:-------:|:---:|
|A355753|	Elijah|
|A382192	|Maxwell 2|

> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.

---
1. `ANIMAL_INS`는 개, 고양이 정보가 담겨 있다. `ANIMAL_TYPE`행에서 먼저 개만 집계한다.

```SQL
WHERE ANIMAL_TYPE = 'Dog'
```

2. 이름에 "EL"이 들어가는 개를 집계한다. 문제에서는 대소문자를 구분하지 않아도 된다고 요구했다. 다시 말해 반드시 대문자 "EL"이 들어가야 할 필요가 없기 때문에 `LIKE '%EL%'`로 집계하면 된다. 
- 해석하면, EL 앞뒤로 어떤 문자가 오든 상관없고 심지어 문자가 오지 않아도 되며 EL은 대,소문자 상관없이 추출한다.

```SQL
WHERE NAME LIKE '%EL%'
```

3. 전체 쿼리를 작성해보면 아래와 같다
```SQL
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS
WHERE NAME LIKE '%EL%'
  AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME
```

|ANIMAL_ID	|NAME|
|:--:|:--:|
|A355753	|Elijah|
|A382192	|Maxwell 2|
|A391858	|Nellie|
|A414198	|Shelly|

4. 만약 대소문자 구분이 필요한 경우라면, MySQL에서는 `BINARY`를 사용하면 된다. 위 쿼리에서 `BINARY`를 함께 사용하면 결과는 아래와 같다. 
```SQL
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS
WHERE BINARY NAME LIKE '%EL%'
  AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME
```
|ANIMAL_ID	|NAME|
|:--:|:--:|
- 대문자 EL을 포함하는 이름이 없기 때문에 어떤 행도 가져오지 못했다.

5. `BINARY`는 함수 형태로도 사용 가능하다. 기능은 동일하다. 여기서는 '%EL%'이 아니라 '%el%'로 추출해서 몇 개의 행을 가져올 수 있도록 하겠다.
```SQL
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS
WHERE BINARY(NAME) LIKE '%el%'
  AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME
```
|ANIMAL_ID	|NAME|
|:--:|:--:|
|A382192	|Maxwell 2|
|A391858	|Nellie|
|A414198	|Shelly|
