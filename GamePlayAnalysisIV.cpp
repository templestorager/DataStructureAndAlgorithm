// Problem Description 
/*
 * SQL Schema
    Table: Activity

    +--------------+---------+
    | Column Name  | Type    |
    +--------------+---------+
    | player_id    | int     |
    | device_id    | int     |
    | event_date   | date    |
    | games_played | int     |
    +--------------+---------+
    (player_id, event_date) is the primary key of this table.
    This table shows the activity of players of some game.
    Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on some day using some device.
    

    Write an SQL query that reports the fraction of players that logged in again on the day after 
    the day they first logged in, rounded to 2 decimal places. In other words, you need to count 
    the number of players that logged in for at least two consecutive days starting from their 
    first login date, then divide that number by the total number of players.

    The query result format is in the following example:

    Activity table:
    +-----------+-----------+------------+--------------+
    | player_id | device_id | event_date | games_played |
    +-----------+-----------+------------+--------------+
    | 1         | 2         | 2016-03-01 | 5            |
    | 1         | 2         | 2016-03-02 | 6            |
    | 2         | 3         | 2017-06-25 | 1            |
    | 3         | 1         | 2016-03-02 | 0            |
    | 3         | 4         | 2018-07-03 | 5            |
    +-----------+-----------+------------+--------------+

    Result table:
    +-----------+
    | fraction  |
    +-----------+
    | 0.33      |
    +-----------+
    Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33
 * 
 */

SELECT ROUND(
        (SELECT COUNT(DISTINCT player_id) 
        FROM activity 
        WHERE (player_id, subdate(event_date, 1)) in 
            (SELECT player_id
                , MIN(event_date)
            FROM Activity
            GROUP BY player_id)) 
        / (SELECT COUNT(DISTINCT player_id)
            FROM activity)
       , 2) as fraction


       1. subquery (each playerid with his/her first login date)
(select player_id, min(event_date) as min_date
from activity
group by player_id) as temp

2. numerator (the number of players that 'logged in for at least two consecutive days starting from their first login date')
sum(case
when temp.min_date + 1 = a.event_date then 1
else 0
end)

3. denominator (the total number of players)
count(distinct temp.player_id)

4. divide
round(numerator/denominator， 2) ---> rounded to 2 decimal places

5. bring 'em together
select round(sum(case when temp.min_date + 1 = a.event_date then 1 else 0 end)
/
count(distinct temp.player_id), 2) as fraction
from (select player_id, min(event_date) as min_date from activity group by player_id) as temp
join activity a
on temp.player_id = a.player_id


       