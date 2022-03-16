-- Solved 2022-03-16
-- Runtime: 301 ms (85.73%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;
