-- Solved 2022-06-07
-- Runtime: 418 ms (86.78%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id IS NULL
    OR referee_id <> 2;
