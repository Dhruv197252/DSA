# Write your MySQL query statement below
SELECT department_name AS Department, employee_name AS Employee, salary AS Salary
FROM (
    SELECT e.id, e.name AS employee_name,e.salary,d.name AS department_name,
    DENSE_RANK() OVER(PARTITION BY e.departmentID
    ORDER BY e.salary DESC) as salary_rank
    FROM Employee AS e
    JOIN Department AS d
    ON e.departmentId = d.id
)t
WHERE salary_rank<=3

