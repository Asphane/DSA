# Write your MySQL query statement below
select c1.id, c1.movie, c1.description, c1.rating
from Cinema c1
join Cinema c2
on c1.id=c2.id
where not c1.id%2=0 and not c1.description = 'boring'
order by c1.rating desc 