-- Write your PostgreSQL query statement below
SELECT
    r.contest_id,
    ROUND(
        COUNT(DISTINCT r.user_id)::numeric/
        (SELECT COUNT(*) FROM Users)*100,2
    ) AS percentage
FROM Register r
RIGHT JOIN Users u
ON r.user_id = u.user_id
WHERE r.contest_id IS NOT NULL
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;