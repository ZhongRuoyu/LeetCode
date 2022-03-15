-- Solved 2022-03-15
-- Runtime: 295 ms (97.35%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee AS e
    INNER JOIN Employee AS m
    ON e.managerId = m.id
WHERE e.salary > m.salary;
