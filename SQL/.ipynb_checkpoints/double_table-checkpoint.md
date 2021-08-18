## leet code | 181. Employees Earning More Than Their Managers


The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

| Id | Name  | Salary | ManagerId |
|:--:|:-----:|:------:|:---------:|
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |


Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

| Employee |
|:--------:|
| Joe      |


---
하나의 테이블을 2번 활용해야 하는 문제다.<br>
이 유형은 `from employee e, employee m`과 같이 동일한 테이블을 2번 불러오거나<br>
`from employee e join employee m using(id)`와 같이 동일한 테이블을 병합하면 된다.


### 1. 동일한 테이블 2번 호출

```sql
select *
from employee e, employee m
```
쿼리를 실행하면, e 테이블의 각각의 행에 m 테이블이 하나씩 중복해서 결합된다.

|Id|Name |Salary|ManagerId|Id |Name |Salary|ManagerId|
|:-:|:--:|:----:|:-------:|:-:|:---:|:----:|:-------:|
|1 |Joe   |70000|        3|1  |Joe  |70000 |3        |
|2 |Henry |80000|        4|1  |Joe  |70000 |3        |
|3 |Sam   |60000|         |1  |Joe  |70000 |3        |
|4 |Max   |90000|         |1  |Joe  |70000 |3        |
|1 |Joe   |70000|        3|2  |Henry|80000 |4        |
|2 |Henry |80000|        4|2  |Henry|80000 |4        |
|3 |Sam   |60000|         |2  |Henry|80000 |4        |
|4 |Max   |90000|         |2  |Henry|80000 |4        |
|1 |Joe   |70000|        3|3  |Sam	|60000 |         |
|2 |Henry |80000|        4|3  |Sam	|60000 |         |
|3 |Sam   |60000|         |3  |Sam	|60000 |         |
|4 |Max   |90000|         |3  |Sam	|60000 |         |
|1 |Joe   |70000|        3|4  |Max	|90000 |         |
|2 |Henry |80000|        4|4  |Max	|90000 |         |
|3 |Sam   |60000|         |4  |Max	|90000 |         |
|4 |Max   |90000|         |4  |Max	|90000 |         |



```sql
select *
from employee e, employee m
where e.managerid = m.id
```
`where`절을 통해 id값을 기준으로 병합할 수 있다. join의 key와 같은 역할을 수행한다.

|Id|Name |Salary|ManagerId|Id |Name |Salary|ManagerId|
|:-:|:--:|:----:|:-------:|:-:|:---:|:----:|:-------:|
|1  |Joe | 70000 | 3      | 3 | Sam |60000 | null|
|2  |Henry| 80000| 4      | 4 | Max |90000 | null|


```sql
select e.name
from employee e, employee m
WHERE e.managerid = m.id
  and e.salary > m.salary
```
문제에서 매니저 급여보다 본인 급여가 높은 사람을 찾으라고 했다.<br>
`where`절을 통해 급여(salary) 조건을 더해주고, 이름만 추출하면 아래와 같다.

|Name|
|:-:|
|Joe |


### 2. 동일한 테이블 병합

```sql
select *
from employee e
join employee m on e.managerid = m.id
```

e를 본인 연봉정보, m을 매니저 연봉정보 집계를 위한 테이블로 사용한다.

|Id|Name |Salary|ManagerId|Id |Name |Salary|ManagerId|
|:-:|:--:|:----:|:-------:|:-:|:---:|:----:|:-------:|
|1  |Joe | 70000 | 3      | 3 | Sam |60000 | null|
|2  |Henry| 80000| 4      | 4 | Max |90000 | null|

그럼, 앞서 `where`절로 병합한 테이블과 동일한 결과가 나온다.

```sql
select e.name
from employee e
join employee m on e.managerid = m.id
where e.salary > m.salary
```

마찬가지로 급여(salary) 조건을 더하고 이름만 추출하면 예상한 결과를 확인할 수 있다.

|Name|
|:-:|
|Joe |