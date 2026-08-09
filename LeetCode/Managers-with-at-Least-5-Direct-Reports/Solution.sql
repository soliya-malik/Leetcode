1# Write your MySQL query statement below
2select e1.name
3from Employee e1
4join Employee e2
5on e1.id = e2.managerId
6group by e2.managerId
7having count(e2.managerId) >= 5