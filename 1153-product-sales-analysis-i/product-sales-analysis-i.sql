# Write your MySQL query statement below
SELECT t2.product_name,t1.year,t1.price
FROM Sales as t1
JOIN Product as t2
ON t1.product_id = t2.product_id