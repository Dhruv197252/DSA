# Write your MySQL query statement below
SELECT t1.customer_id, COUNT(*) AS count_no_trans 
FROM Visits as t1
LEFT JOIN Transactions as t2
ON t1.visit_id = t2.visit_id
WHERE t2.transaction_id is NULL
GROUP BY t1.customer_id