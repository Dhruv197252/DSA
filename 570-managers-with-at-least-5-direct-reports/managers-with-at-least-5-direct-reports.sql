# Write your MySQL query statement below
SELECT t2.name
FROM Employee as t1
JOIN Employee as t2
ON t1.managerId = t2.Id
GROUP BY t2.id, t2.name
HAVING COUNT(*)>=5
