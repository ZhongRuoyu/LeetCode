-- Solved 2022-06-18
-- Runtime: 383 ms (87.24%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT sell_date,
       COUNT(DISTINCT product) AS num_sold,
       GROUP_CONCAT(DISTINCT product
                    ORDER BY product ASC) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date ASC;
