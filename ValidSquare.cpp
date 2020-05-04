// Problem Description

/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
 

Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

// The key point to find a sufficient and necessary condition for being a square:
// 1. four sides are the same length 
// 2. diagonals are also the same length 
// Leveraging this, we can put all the length of pairs of points to a set, and check whether there are only 
// 2 different lengths, but we need to exclude zero length 
// Note: from basic geometry knowledge, we know the length L between two points P1(x1,y1), P2(x2,y2) is calculated as 
// 

// A follow-up question would be to find how the amount of squared than can be formed out of a set of points 
// Idea: 
// 0. Put all the points to a set to remove duplicate points 
// 1. Calculate the length of each pair of points and store them in a hash map, length as the key and pair of points as the value O(n^2)
// 2. Check each of the length and find all possible two pairs of the same length and check whether the four points can form a sqaure 

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        s.insert(distancesquared(p1,p2));
        s.insert(distancesquared(p1,p3));
        s.insert(distancesquared(p1,p4));
        s.insert(distancesquared(p2,p3));
        s.insert(distancesquared(p2,p4));
        s.insert(distancesquared(p3,p4));
        if ( s.size() != 2 )
            return false;
        for ( auto it = s.begin(); it != s.end(); it++ )
            if ( *it == 0 )
                return false;
        return true;
    }
    
    int distancesquared(vector<int> &p1, vector<int>& p2)
    {
        int dist = (p1[1]-p2[1])*(p1[1]-p2[1]) + (p1[0]-p2[0]) *(p1[0]-p2[0]);
        return dist;
    }
};