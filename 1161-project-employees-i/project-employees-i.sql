# Write your MySQL query statement below
SELECT t1.project_id , ROUND(SUM(t2.experience_years)/COUNT(t1.employee_id),2) AS average_years 
FROM Project AS t1
JOIN Employee AS t2
ON t1.employee_id = t2.employee_id
GROUP BY t1.project_id