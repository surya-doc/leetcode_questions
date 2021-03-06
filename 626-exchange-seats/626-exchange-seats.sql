# Write your MySQL query statement below
select(
case
    when mod(id, 2) != 0 and counts != id then id+1
    when mod(id, 2) != 0 and counts = id then id
    else id-1
    end
)
as id, student
from Seat,
(
    select count(*) as counts from Seat
)
as seat_counts
order by id asc;