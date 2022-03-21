-- Solved 2022-03-21
-- Runtime: 414 ms (77.16%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1
    INNER JOIN Weather AS w2
    ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
        AND w1.temperature > w2.temperature;
