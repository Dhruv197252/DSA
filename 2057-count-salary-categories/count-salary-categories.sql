# Write your MySQL query statement below
SELECT
    cat.category,
    COUNT(T.account_id) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION
    SELECT 'Average Salary'
    UNION
    SELECT 'High Salary'
) AS cat
LEFT JOIN (
    SELECT
        account_id,
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
    FROM Accounts
) AS T
ON cat.category = T.category
GROUP BY cat.category;