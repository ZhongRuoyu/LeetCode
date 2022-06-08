-- Solved 2022-06-08
-- Runtime: 381 ms (94.78%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;
