# Write your MySQL query statement below
WITH cte AS(
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) 
SELECT c1.visited_on, SUM(c2.amount) AS amount, ROUND(AVG(c2.amount),2) as average_amount
FROM cte c1
LEFT JOIN cte c2
ON c1.visited_on>=c2.visited_on
WHERE DATEDIFF(c1.visited_on,c2.visited_on) BETWEEN 0 AND 6
AND c1.visited_on>=(
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY) FROM customer
)
GROUP BY c1.visited_on
