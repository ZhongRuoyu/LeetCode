-- Solved 2022-06-26
-- Runtime: 397 ms (99.13%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT product_id
FROM Products
WHERE low_fats = 'Y'
    AND recyclable = 'Y';
