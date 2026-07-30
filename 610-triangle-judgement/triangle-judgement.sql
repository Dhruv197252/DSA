# Write your MySQL query statement below
SELECT x,y,z, 
CASE WHEN x>0 && y>0 && z>0 && (x+y>z) AND (x+z>y) AND (y+z>x) THEN 'Yes'
ELSE 'No'
END AS triangle
FROM Triangle
