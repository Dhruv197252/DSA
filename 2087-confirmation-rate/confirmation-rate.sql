# Write your MySQL query statement below
SELECT t1.user_id, CASE WHEN t2.time_stamp IS NULL 
THEN 0.00 
ELSE ROUND(SUM(t2.action='confirmed')/COUNT(*),2)
END AS confirmation_rate
FROM Signups AS t1
LEFT JOIN Confirmations AS t2
ON t1.user_id=t2.user_id
GROUP BY t1.user_id