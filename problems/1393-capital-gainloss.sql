-- Solved 2022-06-16
-- Runtime: 453 ms (83.93%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT stock_name,
       SUM(capital_gain_loss) AS capital_gain_loss
FROM
    (SELECT stock_name,
            (CASE
                 WHEN operation = 'Buy' THEN -price
                 WHEN operation = 'Sell' THEN price
             END) AS capital_gain_loss
     FROM Stocks) AS CapitalGainLoss
GROUP BY stock_name;
