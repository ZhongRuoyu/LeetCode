-- Solved 2022-06-19
-- Runtime: 309 ms (75.54%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT patient_id,
       patient_name,
       conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%'
    OR conditions LIKE '% DIAB1%';
