# Write your MySQL query statement below

select s1.product_id, s1.year as first_year,s1.quantity,s1.price
from Sales s1
left join Sales s2
on s1.product_id = s2.product_id
and s1.year > s2.year
where s2.year  is null

