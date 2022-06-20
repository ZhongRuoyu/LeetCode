-- Solved 2022-06-20
-- Runtime: 978 ms (95.56%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT customer_id,
       COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN
        (SELECT visit_id
         FROM Transactions)
GROUP BY Visits.customer_id;

/*

Alternatively, using left join:

SELECT Visits.customer_id,
       COUNT(*) AS count_no_trans
FROM Visits
LEFT JOIN Transactions ON Visits.visit_id = Transactions.visit_id
WHERE Transactions.transaction_id IS NULL
GROUP BY Visits.customer_id;

*/
