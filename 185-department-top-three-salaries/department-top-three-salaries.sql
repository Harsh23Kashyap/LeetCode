# Write your MySQL query statement below
Select d.name as Department, e.name as Employee, e.salary as Salary from Employee e JOIN Department d
On e.departmentId = d.id where (

    Select Count(Distinct(e2.salary)) from Employee e2 where e2.salary>e.salary and e.departmentId = e2.departmentId
)<3;