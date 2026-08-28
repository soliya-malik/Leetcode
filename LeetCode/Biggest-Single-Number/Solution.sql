1# Write your MySQL query statement below
2select max(num) as num from
3(select num
4from MyNumbers
5group by num
6having count(num)=1) as new_table