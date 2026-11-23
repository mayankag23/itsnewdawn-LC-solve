-- Write your PostgreSQL query statement below
WITH first AS(
    SELECT product_id,
    MIN(year) AS early_year
    FROM Sales
    GROUP BY product_id 
)
SELECT s.product_id, f.early_year AS first_year, s.quantity, s.price
FROM first f
LEFT JOIN Sales s
ON f.early_year = s.year
AND f.product_id = s.product_id;