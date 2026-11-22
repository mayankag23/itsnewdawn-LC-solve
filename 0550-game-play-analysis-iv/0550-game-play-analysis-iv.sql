-- Write your PostgreSQL query statement below
WITH first_login AS (
    SELECT player_id,
    MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
    )

SELECT ROUND(COUNT(DISTINCT a.player_id) :: numeric / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM first_login f
LEFT JOIN Activity a
ON a.event_date = 1 + f.first_date
AND a.player_id = f.player_id;