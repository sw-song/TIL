## Reference
1. [Tutorial|MySQL Subquery](https://www.mysqltutorial.org/mysql-subquery/)

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

ANIMAL_OUTS 테이블은 동물 보호소에서 입양 보낸 동물의 정보를 담은 테이블입니다. ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, NAME, SEX_UPON_OUTCOME는 각각 동물의 아이디, 생물 종, 입양일, 이름, 성별 및 중성화 여부를 나타냅니다. ANIMAL_OUTS 테이블의 ANIMAL_ID는 ANIMAL_INS의 ANIMAL_ID의 외래 키입니다.

|NAME|	TYPE|	NULLABLE|
|:--:|:--:|:--:|
|ANIMAL_ID|	VARCHAR(N)|	FALSE|
|ANIMAL_TYPE|	VARCHAR(N)|	FALSE|
|DATETIME|	DATETIME|	FALSE|
|NAME	|VARCHAR(N)|	TRUE|
|SEX_UPON_OUTCOME	|VARCHAR(N)	|FALSE|

천재지변으로 인해 일부 데이터가 유실되었습니다. 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL문을 작성해주세요.

### 예시

예를 들어, ANIMAL_INS 테이블과 ANIMAL_OUTS 테이블이 다음과 같다면

> ANIMAL_INS

|ANIMAL_ID|	ANIMAL_TYPE|	DATETIME|	INTAKE_CONDITION|	NAME|	SEX_UPON_INTAKE|
|:--:|:--:|:--:|:--:|:--:|:--:|
|A352713|	Cat|	2017-04-13 16:29:00	|Normal	|Gia	|Spayed Female|
|A350375|	Cat|	2017-03-06 15:01:00	|Normal	|Meo	|Neutered Male|

> ANIMAL_OUTS

ANIMAL_ID	|ANIMAL_TYPE	|DATETIME|	NAME|	SEX_UPON_OUTCOME|
|:--:|:--:|:--:|:--:|:--:|
|A349733	|Dog	|2017-09-27| 19:09:00|	Allie|	Spayed Female|
|A352713	|Cat	|2017-04-25| 12:25:00|	Gia|	Spayed Female|
|A349990	|Cat	|2018-02-02| 14:18:00|	Spice|	Spayed Female|

ANIMAL_OUTS 테이블에서
Allie의 ID는 ANIMAL_INS에 없으므로, Allie의 데이터는 유실되었습니다.
Gia의 ID는 ANIMAL_INS에 있으므로, Gia의 데이터는 유실되지 않았습니다.
Spice의 ID는 ANIMAL_INS에 없으므로, Spice의 데이터는 유실되었습니다.
따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

|ANIMAL_ID|	NAME|
|:--:|:--:|
|A349733	|Allie|
|A349990	|Spice|

> 본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서 제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.
---

1. 차집합을 구하는 문제다. `ANIMAL_OUTS` 테이블에서 `ANIMAL_INS` 와 중복되는 값을 제외하고 남은 값을 가져오면 된다.

2. 우선, SQL에서 차집합을 위한 문법은 별도로 제공하지 않는다. 따라서 JOIN 후 WHERE 문으로 `ANIMAL_INS`에 존재하는 값을 빼주면 되겠다.

3. `ANIMAL_INS`에 존재하는 값을 뺀다는 것은 `ANIMAL_INS`의 JOIN Key 열이 NULL인 경우만 가져온다는 것과 동일하다.

4. 쿼리는 아래와 같다.
```SQL
SELECT O.ANIMAL_ID, O.NAME -- 문제에서 요구하는 열 추출
FROM ANIMAL_INS I 
RIGHT JOIN ANIMAL_OUTS O ON I.ANIMAL_ID = O.ANIMAL_ID -- ANIMAL_OUTS를 집계 기준 열로 한다. 
WHERE I.ANIMAL_ID IS NULL -- 차집합(`ANIMAL_OUTS`- `ANIMAL_INS`)
ORDER BY O.ANIMAL_ID, O.NAME -- 문제에서 id, name 순으로 정렬 요구
```
|ANIMAL_ID	|NAME|
|:--:|:--:|
|A349480	|Daisy|
|A349733	|Allie|
|A349990	|Spice|
|A362137	|*Darcy|

5. 혹은 subquery를 사용할 수도 있다.
```SQL
SELECT ANIMAL_ID, NAME FROM ANIMAL_OUTS
WHERE ANIMAL_ID NOT IN (
    SELECT ANIMAL_ID FROM ANIMAL_INS
)
ORDER BY ANIMAL_ID, NAME
```
|ANIMAL_ID	|NAME|
|:--:|:--:|
|A349480	|Daisy|
|A349733	|Allie|
|A349990	|Spice|
|A362137	|*Darcy|
