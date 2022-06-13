-- Solved 2022-06-13
-- Runtime: 405 ms (85.55%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT activity_date AS day,
       COUNT(DISTINCT user_id) AS active_users
FROM Activity
GROUP BY activity_date
HAVING DATEDIFF('2019-07-27', activity_date) BETWEEN 0 AND 29;
