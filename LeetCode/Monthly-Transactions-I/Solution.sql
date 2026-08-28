1# Write your MySQL query statement below
2select 
3date_format(trans_date,'%Y-%m') as month,
4country,
5count(id) as trans_count,
6sum(if(state = 'approved',1,0)) as approved_count,
7sum(amount) as trans_total_amount ,
8sum(if(state ='approved',amount,0)) as approved_total_amount
9from Transactions
10group by month,country