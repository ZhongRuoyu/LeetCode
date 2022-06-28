-- Solved 2022-06-28
-- Runtime: 493 ms (92.27%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT employee_id,
       (CASE
            WHEN employee_id % 2 <> 0
                 AND name NOT LIKE 'M%' THEN salary
            ELSE 0
        END) AS bonus
FROM Employees
ORDER BY employee_id;
