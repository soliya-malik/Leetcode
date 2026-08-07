1# Write your MySQL query statement below
2select distinct author_id as id 
3from Views 
4where author_id = viewer_id 
5order by author_id