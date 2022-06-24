-- Solved 2022-06-24
-- Runtime: 444 ms (95.19%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT user_id,
       COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;
