-- Solved 2022-03-27
-- Runtime: 232 ms (96.16%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT s1.id,
    IFNULL(s2.student, s1.student) AS student
FROM Seat AS s1
    LEFT JOIN Seat AS s2
    ON (s1.id + 1) ^ 1 - 1 = s2.id
ORDER BY s1.id;
