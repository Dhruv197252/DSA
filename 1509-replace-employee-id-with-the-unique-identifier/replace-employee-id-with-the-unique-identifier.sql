# Write your MySQL query statement below
SELECT t2.unique_id, t1.name 
FROM Employees as t1
LEFT JOIN EmployeeUNI as t2
ON t1.id = t2.id