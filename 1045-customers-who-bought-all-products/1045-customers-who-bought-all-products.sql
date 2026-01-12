# Write your MySQL query statement below
select customer_id
from Customer c, Product p
group by customer_id
having count(distinct c.product_key)=count(distinct p.product_key)