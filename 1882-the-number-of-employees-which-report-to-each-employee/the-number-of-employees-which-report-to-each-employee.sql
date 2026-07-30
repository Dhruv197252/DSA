# Write your MySQL query statement below
SELECT E.employee_id, E.name, COUNT(*) AS reports_count, ROUND(AVG(F.age))AS average_age
FROM Employees E
JOIN Employees F
ON E.employee_id = F.reports_to
GROUP BY E.employee_id, E.name
ORDER BY E.employee_id