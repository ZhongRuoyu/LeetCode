-- Solved 2022-06-11
-- Runtime: 302 ms (97.17%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT actor_id,
       director_id
FROM ActorDirector
GROUP BY actor_id,
         director_id
HAVING COUNT(*) >= 3;
