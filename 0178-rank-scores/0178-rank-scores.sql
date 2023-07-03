# Write your MySQL query statement below
Select s1.score, (select count(distinct s2.score) from Scores s2 where s2.score>=s1.score) As 'rank' from Scores s1 order by s1.score DESC;