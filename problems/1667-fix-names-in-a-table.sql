-- Solved 2022-06-22
-- Runtime: 543 ms (91.89%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT user_id,
       CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;

-- Happy anniversary!
