// Problem Description
/*
    SQL Schema
    Table point holds the x coordinate of some points on x-axis in a plane, which are all integers.
    

    Write a query to find the shortest distance between two points in these points.
    

    | x   |
    |-----|
    | -1  |
    | 0   |
    | 2   |
    

    The shortest distance is '1' obviously, which is from point '-1' to '0'. So the output is as below:
 * 
 * 
 */

select 
    min(abs(p1.x-p2.x)) as shortest
from 
    point p1
        join
    point p2 on p1.x != p2.x