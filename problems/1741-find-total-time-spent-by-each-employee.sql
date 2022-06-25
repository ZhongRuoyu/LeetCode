-- Solved 2022-06-25
-- Runtime: 452 ms (85.91%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT event_day AS day,
       emp_id,
       SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY event_day,
         emp_id;
