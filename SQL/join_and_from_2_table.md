## 테이블 병합 - JOIN 미사용 / 사용

---

## 예제 테이블 A, B

> TableA

| IDX | Key   | Sex | Name |
| :--:| :--:  |:-:  |:-:   |
| 1| 102   | M   | JAY   |
| 2| 104   | M   | MINSU |
| 3| 105   | M   | TOM   |
| 4| 202   | F   | JENNIE|
| 5| 206   | F   | MINA  |


> TableB

| IDX | Key   | Height | Weight | Age |
|:--:| :--:  | :-:    | :-:    |  :-:|
|1| 201   | 170    | 70     | 18  |
|2| 202   | 161    | 52     | 22  |
|3| 203   | 166    | 57     | 22  |
|4| 204   | 171    | 79     | 22  |
|5| 206   | 156    | 48     | 26  |

---

### JOIN 미사용

> 1. `FROM`을 통해 테이블을 동시에 가져온다.

```SQL
SELECT * FROM TableA, TableB
```
| IDX | Key   | Sex | Name |IDX | Key   | Height | Weight | Age |
| :--:| :--:  |:-:  |:-:   |:--:| :--:  | :-:    | :-:    |  :-:|
| 1| 102   | M   | JAY   |1| 201   | 170    | 70     | 18  |
| 1| 102   | M   | JAY   |2| 202   | 161    | 52     | 22  |
| 1| 102   | M   | JAY   |3| 203   | 166    | 57     | 22  |
| 1| 102   | M   | JAY   |4| 204   | 171    | 79     | 22  |
| 1| 102   | M   | JAY   |5| 206   | 156    | 48     | 26  |
.
.
.(생략)

> 2. `WHERE`을 통해 특정 Column 기준 공통 행을 추출할 수 있다.

```SQL
SELECT * FROM TableA A, TableB B
WHERE A.IDX = B.IDX
```
| IDX | Key   | Sex | Name | IDX | Key   | Height | Weight | Age |
| :--:| :--:  |:-:  |:-:   |:--:| :--:  | :-:    | :-:    |  :-:|
| 1| 102   | M   | JAY   |1| 201   | 170    | 70     | 18  |
| 2| 104   | M   | MINSU |2| 202   | 161    | 52     | 22  |
| 3| 105   | M   | TOM   |3| 203   | 166    | 57     | 22  |
| 4| 202   | F   | JENNIE|4| 204   | 171    | 79     | 22  |
| 5| 206   | F   | MINA  |5| 206   | 156    | 48     | 26  |

> 3. `SELECT`로 일부 필요한 Column만 추출하면 깔끔하게 병합할 수 있다.
```SQL
SELECT A.Key, A.Name, B.Age FROM TableA A, TableB B
WHERE A.Key = B.Key
```
| Key   | Name | Age |
| :--:  | :-:    | :-:|
| 202   | JENNIE| 22|
| 206   |  MINA  | 26|


---

### JOIN 사용

```SQL
SELECT A.Key, A.Name, B.Age FROM TableA A
JOIN TableB B ON A.Key = B.Key
```
| Key   | Name | Age |
| :--:  | :-:    | :-:|
| 202   | JENNIE| 22|
| 206   |  MINA  | 26|



