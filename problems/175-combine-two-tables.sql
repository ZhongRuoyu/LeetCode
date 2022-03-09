-- Solved 2022-03-09
-- Runtime: 338 ms (79.07%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;
