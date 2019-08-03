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
    

    Write an SQL query that reports for each player and date, how many games played so far by the player. That is, the total number of games played by the player until that date. Check the example for clarity.

    The query result format is in the following example:

    Activity table:
    +-----------+-----------+------------+--------------+
    | player_id | device_id | event_date | games_played |
    +-----------+-----------+------------+--------------+
    | 1         | 2         | 2016-03-01 | 5            |
    | 1         | 2         | 2016-05-02 | 6            |
    | 1         | 3         | 2017-06-25 | 1            |
    | 3         | 1         | 2016-03-02 | 0            |
    | 3         | 4         | 2018-07-03 | 5            |
    +-----------+-----------+------------+--------------+

    Result table:
    +-----------+------------+---------------------+
    | player_id | event_date | games_played_so_far |
    +-----------+------------+---------------------+
    | 1         | 2016-03-01 | 5                   |
    | 1         | 2016-05-02 | 11                  |
    | 1         | 2017-06-25 | 12                  |
    | 3         | 2016-03-02 | 0                   |
    | 3         | 2018-07-03 | 5                   |
    +-----------+------------+---------------------+
    For the player with id 1, 5 + 6 = 11 games played by 2016-05-02, and 5 + 6 + 1 = 12 games played by 2017-06-25.
    For the player with id 3, 0 + 5 = 5 games played by 2018-07-03.
    Note that for each player we only care about the days when the player logged in.
 * 
 */

SELECT player_id, event_date,
       (CASE WHEN rank = 1 THEN (@cum := @cum + games_played)
                   ELSE (@cum := games_played)
                   END) AS games_played_so_far
FROM (SELECT player_id, event_date, games_played,(@prev = (@prev := player_id)) AS rank
            FROM Activity, 
                       (SELECT @prev := (SELECT player_id FROM Activity LIMIT 1)) AS t
                        ORDER BY player_id, event_date) AS a,
      (SELECT @cum := 0) AS b;


SELECT a1.player_id, a1.event_date, SUM(a2.games_played) as games_played_so_far
FROM Activity a1
JOIN Activity a2
on a1.player_id=a2.player_id and a1.event_date>=a2.event_date
GROUP BY a1.player_id,a1.event_date