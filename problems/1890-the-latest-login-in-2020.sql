-- Solved 2022-06-29
-- Runtime: 592 ms (73.64%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT user_id,
       MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY user_id;
