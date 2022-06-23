-- Solved 2022-06-23
-- Runtime: 518 ms (71.76%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT date_id,
       make_name,
       COUNT(DISTINCT lead_id) AS unique_leads,
       COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id,
         make_name;
