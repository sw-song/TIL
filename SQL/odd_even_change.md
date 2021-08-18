## leet code | 626. Exchange Seats

Mary is a teacher in a middle school and she has a table seat storing students' names and their corresponding seat ids.

The column id is continuous increment.

Mary wants to change seats for the adjacent students.

Can you write a SQL query to output the result for Mary?

 
|    id   | student |
|:-------:|:-------:|
|    1    | Abbot   |
|    2    | Doris   |
|    3    | Emerson |
|    4    | Green   |
|    5    | Jeames  |

For the sample input, the output is:

|    id   | student |
|:-------:|:-------:|
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    4    | Emerson |
|    5    | Jeames  |

Note:

If the number of students is odd, there is no need to change the last one's seat.


---
문제를 해석하면, student를 가까운 id(홀,짝)끼리 바꾸고, 총 학생 수가 홀수라면 마지막 student는 그대로 둔다.

이를 student가 아니라 id를 기준으로 생각하면 접근하기 쉽다.
즉, student를 바꾸는 것이 아닌 id를 바꾸고 `order by`하면 된다.

1. '마지막 id'를 확인할 수 있도록 열을 추가한다.

```sql
select *
from seat s
left join (select max(id) id
           from seat) m on s.id = m.id
```

|   s.id  |s.student|m.id|
|:-------:|:-------:|:--:|
|    1    | Abbot   |    |
|    2    | Doris   |    |
|    3    | Emerson |    |
|    4    | Green   |    |
|    5    | Jeames  |  5 |


2. 다음으로, 짝수 id는 1 줄이고, 홀수 id는 1을 더하되 마지막 id가 홀수라면 그대로 둔다. 마지막 id가 짝수라면 홀/짝을 모두 맞바꾸면 된다.

```sql

select case when (s.id %2 = 1 and m.id is null) then s.id+1
            when (s.id %2 = 1 and m.id is not null) then s.id
            when s.id %2 = 0 then s.id-1 end as id, s.student
from seat s
left join (select max(id) id
           from seat) m on s.id = m.id
```

구조적으로 접근해보면, id가 홀수면 해당 id가 마지막 id인지 확인이 필요하다. 마지막 id라면 그대로 유지하고 그렇지 않다면 1을 더해줘서 짝수로 만든다.<br>
반대로 id가 짝수라면 모두 1을 빼서 홀수로 만들어주면 된다.

`case when`절을 사용하여 이 내용을 수행했다.

|   s.id  |s.student|
|:-------:|:-------:|
|    2    | Abbot   |
|    1    | Doris   |
|    4    | Emerson |
|    3    | Green   |
|    5    | Jeames  |


3. 정렬한다.


```sql
select case when (s.id %2 = 1 and m.id is null) then s.id+1
            when (s.id %2 = 1 and m.id is not null) then s.id
            when s.id %2 = 0 then s.id-1 end as id, s.student
from seat s
left join (select max(id) id
           from seat) m on s.id = m.id
order by id
```

|   s.id  |s.student|
|:-------:|:-------:|
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    3    | Emerson |
|    5    | Jeames  |