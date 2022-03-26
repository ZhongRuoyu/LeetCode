-- Solved 2022-03-26
-- Runtime: 175 ms (91.01%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT id, movie, description, rating
FROM Cinema
WHERE id % 2 <> 0
    AND description <> 'boring'
ORDER BY rating DESC;
