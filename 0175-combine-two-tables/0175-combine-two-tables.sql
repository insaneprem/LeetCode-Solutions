# Write your MySQL query statement below
select p.firstName,p.lastName,a.city,a.state 
from Person As p left Join Address As a on p.personId = a.personId