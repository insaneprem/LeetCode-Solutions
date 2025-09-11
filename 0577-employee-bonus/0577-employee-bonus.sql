# Write your MySQL query statement below
SELECT e.name,b.bonus from 
Employee e Left Join Bonus b on e.empId = b.empId
where b.bonus<1000 || b.bonus is null