# Write your MySQL query statement below
select p.firstName, p.lastName, if(Null, Null, a.city) as city, if(Null, Null, a.state) as state
from Person p
left join Address a
on p.personId=a.personId;