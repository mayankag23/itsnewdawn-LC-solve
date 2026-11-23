-- Write your PostgreSQL query statement below
WITH new_table AS(
    SELECT customer_id, MIN(order_date) AS min_order_date
    FROM Delivery
    GROUP BY customer_id 
)
SELECT ROUND((SUM(CASE WHEN n.min_order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END) :: numeric/COUNT(DISTINCT d.customer_id))*100,2) AS immediate_percentage
FROM new_table n
LEFT JOIN Delivery d
ON n.min_order_date = d.order_date
AND n.customer_id = d.customer_id