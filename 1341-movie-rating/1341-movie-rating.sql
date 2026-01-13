 (select name as results
 from Users u
 join MovieRating m1
 on u.user_id=m1.user_id
 group by m1.user_id
 order by count(rating) desc, name
 limit 1)

 union all

(select title as results
from Movies m2
join MovieRating m1
on m2.movie_id=m1.movie_id
where month(created_at)='02' and year(created_at)='2020'
group by m2.title
order by avg(rating) desc, title
limit 1)
