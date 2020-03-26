// Problem Description 
/*
 
 Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9
*/

// Idea:
// We first need to understand that the path here can include revisited nodes, which is 
// different from finding the shortest path (BFS) or the minimum move (Greedy). 
// We maintain a set of nodes which are accessible from the nodes we visited so far and select the 
// maximum from the set for each next step, which priority queue would facilitate. 

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int GlobalMin = A[0][0];
        priority_queue<pair<int,pair<int,int>>> neighbors;
        int r = A.size(), c = A[0].size();
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        vector<vector<int> > direction{{-1,0},{1,0},{0,1},{0,-1}};
        neighbors.push({A[0][0],{0,0}});
        visited[0][0] = true;
        while(!neighbors.empty())
        {
            auto pos = neighbors.top();
            neighbors.pop();
            GlobalMin = min(pos.first,GlobalMin);
            if ( pos.second.first == r - 1 && pos.second.second == c-1 )
            {
                return GlobalMin;
            }
            for ( int dir = 0; dir < direction.size(); dir++ )
            {
                int new_x = pos.second.first + direction[dir][0];
                int new_y = pos.second.second + direction[dir][1];
                if ( new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && !visited[new_x][new_y] )
                {
                    neighbors.push({A[new_x][new_y],{new_x,new_y}});
                    visited[new_x][new_y] = true;
                }
            }
        }
        
        return -1;
    }
};