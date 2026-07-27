SELECT
    ROUND(SUM(order_date = customer_pref_delivery_date) * 100 / COUNT(*), 2)
    AS immediate_percentage
FROM
(
    SELECT *,
           RANK() OVER(PARTITION BY customer_id ORDER BY order_date) AS rn
    FROM Delivery
) t
WHERE rn = 1;