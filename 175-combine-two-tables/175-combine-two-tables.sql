/* Write your PL/SQL query statement below */
Select firstName, lastName, city , state from Person p left join Address a on p.personId=a.personId;