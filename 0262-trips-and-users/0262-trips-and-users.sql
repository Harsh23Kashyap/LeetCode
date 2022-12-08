# Write your MySQL query statement below
# SELECT Request_at AS Day, ROUND(SUM(IF(Status = 'completed', 0, 1))/COUNT(Status),2) as 'Cancellation Rate' 
# FROM Trips 
# WHERE Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes') 
#     AND Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes')
#     AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
# GROUP BY Trips.Request_at

Select request_at as Day,  Round(Sum(If(status='completed',0,1))/count(status),2) as 'Cancellation Rate'
from Trips 
    where 
        (client_id not in (select users_id from Users where banned='Yes'))
    and (driver_id not in (select users_id from Users where banned='Yes'))
    and request_at  BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at
