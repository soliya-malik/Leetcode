1# Write your MySQL query statement below
2select q1.person_name
3from queue q1
4inner join queue q2
5on q1.turn >= q2.turn
6group by q1.turn
7having sum(q2.weight) <= 1000
8order by q1.turn desc limit 1 