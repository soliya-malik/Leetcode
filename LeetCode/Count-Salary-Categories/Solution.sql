1# Write your MySQL query statement below
2select "Low Salary" as category,
3sum(if(income < 20000,1,0)) as accounts_count
4from Accounts
5
6union
7
8select "Average Salary" as category,
9sum(if(income BETWEEN 20000 and 50000,1,0)) as accounts_count
10from Accounts
11
12union
13
14select "High Salary" as category,
15sum(if(income > 50000,1,0)) as accounts_count
16from Accounts