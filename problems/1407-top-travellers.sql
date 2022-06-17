-- Solved 2022-06-17
-- Runtime: 659 ms (86.24%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Users.name,
       IFNULL(SUM(Rides.distance), 0) AS travelled_distance
FROM Users
LEFT JOIN Rides ON Users.id = Rides.user_id
GROUP BY Users.id
ORDER BY travelled_distance DESC,
         name ASC;
