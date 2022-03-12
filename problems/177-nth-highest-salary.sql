-- Solved 2022-03-12
-- Runtime: 275 ms (95.82%)
-- Memory Usage: 0 B (100.00%)

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT DEFAULT N - 1;
    RETURN (
        # Write your MySQL query statement below.
        SELECT (
            SELECT DISTINCT salary
            FROM Employee
            ORDER BY salary DESC
            LIMIT 1 OFFSET M
        )
    );
END
