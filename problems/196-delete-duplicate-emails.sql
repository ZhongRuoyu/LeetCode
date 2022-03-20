-- Solved 2022-03-20
-- Runtime: 498 ms (88.24%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (
    SELECT id
    FROM (
        SELECT MIN(id) AS id
        FROM Person
        GROUP BY email
    ) AS Temp
);



/*

A slower version with inner join:

DELETE p1
FROM Person p1
    INNER JOIN Person p2
    ON p1.email = p2.email
        AND p1.id > p2.id;

*/
