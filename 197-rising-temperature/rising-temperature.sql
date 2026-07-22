# Write your MySQL query statement below
SELECT t1.Id 
FROM Weather as t1
JOIN Weather as t2
ON DATEDIFF(t1.recordDate,t2.recordDate)=1
AND t1.temperature>t2.temperature