-- Solved 2022-06-09
-- Runtime: 1169 ms (68.06%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN
        (SELECT Orders.sales_id
         FROM Company
         INNER JOIN Orders ON Company.com_id = Orders.com_id
         WHERE Company.name = 'RED' );
