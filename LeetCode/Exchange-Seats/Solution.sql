1# Write your MySQL query statement below
2select 
3case
4when id = (select max(id) from seat) and id%2=1 then id
5when id%2=1 then id+1 else id-1 end as id,
6student
7from seat 
8order by id