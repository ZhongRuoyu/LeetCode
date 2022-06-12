-- Solved 2022-06-12
-- Runtime: 958 ms (91.70%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT product_id,
       product_name
FROM Product
WHERE product_id NOT IN
        (SELECT product_id
         FROM Sales
         WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31' );
