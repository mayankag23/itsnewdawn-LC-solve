-- Write your PostgreSQL query statement below
SELECT 
c.customer_id
FROM Customer c
GROUP BY c.customer_id
HAVING COUNT(DISTINCT c.product_key)=(SELECT COUNT(*) product_id FROM Product)