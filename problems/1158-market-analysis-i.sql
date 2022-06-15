-- Solved 2022-06-15
-- Runtime: 942 ms (94.33%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Users.user_id AS buyer_id,
       Users.join_date,
       COUNT(Orders.order_id) AS orders_in_2019
FROM Users
LEFT JOIN Orders ON Users.user_id = Orders.buyer_id
AND YEAR(order_date) = 2019
GROUP BY Users.user_id;

/*

An alternative solution using temporary view:

# Write your MySQL query statement below
WITH OrdersIn2019 AS
    (SELECT buyer_id,
            COUNT(order_id) AS orders_in_2019
     FROM Orders
     WHERE YEAR(Orders.order_date) = 2019
     GROUP BY buyer_id)
SELECT user_id AS buyer_id,
       join_date,
       IFNULL(
                  (SELECT OrdersIn2019.orders_in_2019
                   FROM OrdersIn2019
                   WHERE Users.user_id = OrdersIn2019.buyer_id), 0) AS orders_in_2019
FROM Users;

*/
