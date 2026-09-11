1# Write your MySQL query statement below
2select visited_on ,
3(
4    select sum(amount)
5    from Customer
6    where visited_on Between DATE_SUB(c.visited_on,INTERVAL 6 DAY)
7    and c.visited_on
8) AS amount,
9round((
10     select sum(amount)/7
11    from Customer
12    where visited_on Between DATE_SUB(c.visited_on,INTERVAL 6 DAY)
13    and c.visited_on
14),2) AS average_amount 
15
16
17
18from Customer c 
19where visited_on >=
20(
21    select DATE_ADD(min(visited_on),INTERVAL 6 DAY)
22    from Customer
23)
24group by visited_on
25order by visited_on
26