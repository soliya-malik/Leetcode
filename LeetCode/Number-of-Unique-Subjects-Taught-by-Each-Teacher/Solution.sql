1# Write your MySQL query statement below
2select teacher_id ,
3count(distinct subject_id )as cnt
4from Teacher
5group by teacher_id