-- Solved 2022-03-23
-- Runtime: 242 ms (91.92%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000
    OR population >= 25000000;
