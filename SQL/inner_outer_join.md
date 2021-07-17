## Reference
1. [[MySQL] Inner Join과 Left Join의 차이](https://jaenjoy.tistory.com/7)

![image](https://blog.kakaocdn.net/dn/bbcaHr/btqCUytJ73t/dfNLQnhKypZ3fgJ4JjpqZk/img.jpg)


## Sample Table Info-

> TableA

| Key   | Sex | Name |
| :--:  |:-:  |:-:   |
| 102   | M   | JAY   |
| 104   | M   | MINSU |
| 105   | M   | TOM   |
| 202   | F   | JENNIE|
| 206   | F   | MINA  |


> TableB

| Key   | Height | Weight | Age |
| :--:  | :-:    | :-:    |  :-:|
| 201   | 170    | 70     | 18  |
| 202   | 161    | 52     | 22  |
| 203   | 166    | 57     | 22  |
| 204   | 171    | 79     | 22  |
| 206   | 156    | 48     | 26  |


### INNER JOIN (=JOIN)
- `INNER JOIN` 결합하고자 하는 기준 열의 교집합에 해당하는 행을 모두 가져온다.
- `JOIN` 으로 줄여쓸 수 있다.

> INNER JOIN (A & B)
```sql
SELECT A.Key, A.Sex, A.Name, B.Age FROM TableA AS A
JOIN TableB AS B ON A.Key = B.Key
```

| Key   | Sex | Name | Age |
| :--:  |:-:|:-:|:-:|
| 202     | F | JENNIE | 22 |
| 206     | F | MINA  | 26 |


## OUTER JOIN
- `OUTER JOIN`의 유형은 크게 3가지로 아래와 같다.
1. LEFT JOIN
2. RIGHT JOIN
3. FULL OUTER JOIN (MySQL 지원 x)

> 1. LEFT JOIN (A)
```sql
SELECT A.Key, A.Sex, A.Name, B.Age FROM TableA AS A
LEFT JOIN TableB AS B ON A.Key = B.Key
```
| Key   | Sex | Name | Age |
| :--:  |:-:  |:-:   | :-: |
| 102   | M | JAY   |<null>|
| 104   | M | MINSU |<null>|
| 105   | M | TOM   |<null>|
| 202   | F | JENNIE| 22   |
| 206   | F | MINA  | 26   |

> 2. RIGHT JOIN (B)
```sql
SELECT A.Key, A.Sex, A.Name, B.Age FROM TableA AS A
RIGHT JOIN TableB AS B ON A.Key = B.Key
```
| Key   | Sex | Name | Age |
| :--:  | :-:    | :-:    |  :-:|
| 201   | <null>| <null> | 18  |
| 202   |  F    | JENNIE | 22  |
| 203   | <null>| <null> | 22  |
| 204   | <null>| <null> | 22  |
| 206   | F     | MINA | 26  |

> 3. FULL OUTER JOIN (A + B)
- MySQL은 `FULL OUTER JOIN`을 별도로 지원하지 않는다. 따라서 `union`을 통해 `LEFT JOIN`과 `RIGHT JOIN`의 결과를 합치는 방식을 사용한다.
```sql
SELECT A.Key, A.Sex, A.Name, B.Age FROM TableA AS A
LEFT JOIN TableB AS B ON A.Key = B.Key
union
SELECT A.Key, A.Sex, A.Name, B.Age FROM TableA AS A
RIGHT JOIN TableB AS B ON A.Key = B.Key
```
| Key   | Sex | Name | Age |
| :--:  |:-:  |:-:   | :-: |
| 102   | M | JAY   |<null>|
| 104   | M | MINSU |<null>|
| 105   | M | TOM   |<null>|
| 201   | <null>| <null> | 18  |
| 202   |  F    | JENNIE | 22  |
| 203   | <null>| <null> | 22  |
| 204   | <null>| <null> | 22  |
| 206   | F     | MINA | 26  |

## OUTER JOIN - except INNER JOIN 
- `OUTER JOIN`시 양쪽 테이블의 공통 값은 제외할 때가 있다. 이를 위한 별도의 문법은 없기 때문에 `WHERE`로 처리해준다.
- 아래 예시는 Table A에만 존재하는 Key값과 해당 행을 모두 불러온다.(남성만 집계)

> LEFT JOIN (A-B)
```sql
SELECT A.Key, A.Sex, A.Name FROM TableA AS A
LEFT JOIN TableB AS B ON A.Key = B.Key
WHERE B.Key is NULL
```

| Key   | Sex | Name | 
| :--:  |:-:  |:-:   |
| 102   | M   | JAY   |
| 104   | M   | MINSU |
| 105   | M   | TOM   |
