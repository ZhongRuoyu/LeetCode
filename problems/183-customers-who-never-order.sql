-- Solved 2022-03-17
-- Runtime: 413 ms (80.96%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE id NOT IN (
    SELECT customerId
    FROM Orders
);

-- I did it!
