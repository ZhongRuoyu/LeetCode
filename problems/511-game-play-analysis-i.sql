-- Solved 2022-06-06
-- Runtime: 424 ms (99.62%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT player_id,
       MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
