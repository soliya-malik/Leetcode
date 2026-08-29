1# Write your MySQL query statement below
2select x,y,z ,
3case when x+y > z and y+z>x and x+z>y then 'Yes' else 'No' end as triangle 
4from Triangle