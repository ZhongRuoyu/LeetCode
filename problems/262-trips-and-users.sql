-- Solved 2022-03-22
-- Runtime: 418 ms (92.42%)
-- Memory Usage: 0 B (100.00%)

# Write your MySQL query statement below
SELECT Day,
    ROUND(SUM(CASE status WHEN 'completed' THEN 0 ELSE 1 END) / COUNT(*), 2) AS 'Cancellation Rate'
FROM (
    SELECT status,
        request_at AS Day
    FROM Trips
        INNER JOIN Users AS Clients
        ON Trips.client_id = Clients.users_id
            AND Clients.banned = 'No'
        INNER JOIN Users AS Drivers
        ON Trips.driver_id = Drivers.users_id
            AND Drivers.banned = 'No'
) AS Unbanned
WHERE Day BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Day;
