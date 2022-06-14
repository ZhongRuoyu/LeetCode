-- Solved 2022-06-14
-- Runtime: 359 ms (93.05%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC;
