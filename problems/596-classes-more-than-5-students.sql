-- Solved 2022-03-24
-- Runtime: 253 ms (84.34%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(*) >= 5;
