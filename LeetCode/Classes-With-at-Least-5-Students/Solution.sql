1# Write your MySQL query statement below
2select class 
3from courses 
4group by class
5having count(student) >= 5