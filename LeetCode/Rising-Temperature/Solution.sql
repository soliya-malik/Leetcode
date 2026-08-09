1# Write your MySQL query statement below
2select w1.id
3from Weather w1,Weather w2
4where datediff(w1.recordDate ,w2.recordDate) =1
5and w1.temperature > w2.temperature