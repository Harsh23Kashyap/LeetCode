# Write your MySQL query statement below
Select c.name as Customers from Customers c where c.id NOT IN (Select customerId from Orders);