1# Write your MySQL query statement below
2select eu.unique_id , e.name
3from Employees as e 
4left join EmployeeUNI as eu
5on e.id = eu.id