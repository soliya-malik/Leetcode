1# Write your MySQL query statement below
2select * from Cinema
3where id %2 != 0 
4and description != 'boring'
5order by rating desc