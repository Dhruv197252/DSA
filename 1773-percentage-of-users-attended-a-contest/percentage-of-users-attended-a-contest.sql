# Write your MySQL query statement below
SELECT t2.contest_id, ROUND(COUNT(t2.user_id)*100/(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Users as t1
RIGHT JOIN Register as t2
ON t1.user_id=t2.user_id
GROUP BY t2.contest_id
ORDER BY percentage DESC, t2.contest_id ASC