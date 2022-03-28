-- Solved 2022-03-28
-- Runtime: 194 ms (94.92%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
UPDATE Salary
SET sex = (CASE sex
    WHEN 'm' THEN 'f'
    WHEN 'f' THEN 'm'
    ELSE NULL
END);
