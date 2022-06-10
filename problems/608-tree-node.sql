-- Solved 2022-06-10
-- Runtime: 382 ms (84.13%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT id,
       (CASE
            WHEN p_id IS NULL THEN 'Root'
            WHEN NOT EXISTS
                     (SELECT id
                      FROM Tree AS T
                      WHERE T.p_id = Tree.id ) THEN 'Leaf'
            ELSE 'Inner'
        END) AS type
FROM Tree
ORDER BY id ASC;
