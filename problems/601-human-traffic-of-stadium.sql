-- Solved 2022-03-25
-- Runtime: 256 ms (98.93%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT DISTINCT id, visit_date, people
FROM Stadium
INNER JOIN (
    SELECT a.id AS from_id,
        c.id AS to_id
    FROM Stadium AS a
        INNER JOIN Stadium AS b
        ON a.id + 1 = b.id
            AND a.people >= 100
            AND b.people >= 100
        INNER JOIN Stadium AS c
        ON b.id + 1 = c.id
            AND c.people >= 100
) AS Temp
    ON id BETWEEN from_id AND to_id;
