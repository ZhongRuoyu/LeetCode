-- Solved 2022-03-11
-- Runtime: 185 ms (81.41%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
