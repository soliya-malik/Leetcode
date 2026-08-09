1# Write your MySQL query statement below
2select s.student_id,s.student_name,sub.subject_name,
3count(e.subject_name) as  attended_exams
4from Students s
5cross join subjects sub
6left join examinations as e 
7on s.student_id = e.student_id
8and e.subject_name = sub.subject_name
9
10group by s.student_id,s.student_name,sub.subject_name
11order by s.student_id,s.student_name