-- Solved 2022-03-19
-- Runtime: 629 ms (93.46%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM (
    SELECT Department.name AS Department,
        Employee.name AS Employee,
        salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS Ranking
    FROM Employee
        INNER JOIN Department
        ON Employee.departmentId = Department.id
) AS Temp
WHERE Ranking <= 3;



/*

Another solution without DENSE_RANK:

SELECT d.name AS Department,
    e1.name AS Employee,
    e1.salary AS Salary
FROM Employee AS e1
    INNER JOIN Department AS d
    ON e1.departmentId = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee AS e2
    WHERE e1.departmentId = e2.departmentId
        AND e1.salary < e2.salary
);

/*
