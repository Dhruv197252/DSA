# Write your MySQL query statement below
SELECT name as results
FROM (
    SELECT u.name, COUNT(*) AS ratings_count
    FROM Users u
    JOIN MovieRating mr
    ON u.user_id=mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY ratings_count DESC, u.name ASC 
    LIMIT 1
) t

UNION ALL

SELECT title as results
FROM (
    SELECT m.title, AVG(mr.rating) AS avg_rating
    FROM Movies m
    JOIN MovieRating mr
    ON m.movie_id=mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id, m.title
    ORDER BY avg_rating DESC, m.title ASC
    LIMIT 1
) u