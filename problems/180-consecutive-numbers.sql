-- Solved 2022-03-14
-- Runtime: 419 ms (85.16%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
        ROW_NUMBER() OVER (
            PARTITION BY num
            ORDER BY id
        ) AS num_id,
        ROW_NUMBER() OVER (
            ORDER BY id
        ) AS consecutive_id
    FROM Logs
) AS Temp
GROUP BY num, consecutive_id - num_id
HAVING COUNT(*) >= 3;
