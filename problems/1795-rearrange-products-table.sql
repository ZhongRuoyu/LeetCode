-- Solved 2022-06-27
-- Runtime: 422 ms (95.61%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT product_id,
       'store1' AS store,
       store1 AS price
FROM Products
WHERE store1 IS NOT NULL
UNION
SELECT product_id,
       'store2' AS store,
       store2 AS price
FROM Products
WHERE store2 IS NOT NULL
UNION
SELECT product_id,
       'store3' AS store,
       store3 AS price
FROM Products
WHERE store3 IS NOT NULL;
