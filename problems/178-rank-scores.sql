-- Solved 2022-03-13
-- Runtime: 248 ms (80.53%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT score,
    DENSE_RANK() OVER (
        ORDER BY score DESC
    ) AS 'rank'
FROM Scores;



/*

Another solution without DENSE_RANK:

SELECT score,
    (
        SELECT count(DISTINCT score)
        FROM Scores s2
        WHERE s2.score >= s1.score
    ) AS 'rank'
FROM Scores s1
ORDER BY score DESC;

*/
