-- Solved 2022-03-18
-- Runtime: 565 ms (69.01%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Department.name AS Department,
    Employee.name AS Employee,
    salary AS Salary
FROM Employee
    INNER JOIN Department
    ON Employee.departmentId = Department.id
WHERE (departmentId, salary) IN (
    SELECT departmentId, MAX(salary)
    FROM Employee
    GROUP BY departmentId
);
