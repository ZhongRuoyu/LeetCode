-- Solved 2022-06-30
-- Runtime: 481 ms (80.80%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Salaries.employee_id
FROM Employees
RIGHT JOIN Salaries ON Employees.employee_id = Salaries.employee_id
WHERE Employees.name IS NULL
UNION
SELECT Employees.employee_id
FROM Employees
LEFT JOIN Salaries ON Employees.employee_id = Salaries.employee_id
WHERE Salaries.salary IS NULL
ORDER BY employee_id;

-- Too bad full outer join is not available in MySQL...
