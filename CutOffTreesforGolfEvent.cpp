// Problem Description
/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
In one step you can walk in any of the four directions top, bottom, left and right also when standing in a point which is a tree you can decide whether or not to cut off the tree.

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 

Example 2:

Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 

Example 3:

Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
 

Constraints:

1 <= forest.length <= 50
1 <= forest[i].length <= 50
0 <= forest[i][j] <= 10^9
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


// Step 1: Sort all the positions and find the next position to be visited
// Step 2: For the next position, we calcaluate the steps it takes to reach the next position in a BFS manner 
// Step 3: repeat the above to steps until all trees have been cut 

#if 0
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int sr = 0, sc = 0, steps = 0;
        int Nr = forest.size(), Nc = forest[0].size();
        #if 0
        unordered_map<int, pair<int,int> > m;
        for ( int i = 0; i < Nr; i++ )
            for ( int j = 0; j < Nc; j++ )
            {
                if ( forest[i][j] > 1 )
                {
                    m[forest[i][j]]  = {i,j};
                }
            }
        sort( m.begin(), m.end() );
        #endif 
        
        vector<vector<int> > sorted_pos;
        for ( int i = 0; i < Nr; i++ )
            for ( int j = 0; j < Nc; j++ )
            {
                if ( forest[i][j] > 1 )
                    sorted_pos.push_back({forest[i][j],i,j});
            }
        sort ( sorted_pos.begin(), sorted_pos.end() );
        
        for ( int i = 0; i < sorted_pos.size(); i++ )
        {
            int next_row = sorted_pos[i][1];
            int next_col = sorted_pos[i][2];
            int moves = bfs(forest,sr,sc,next_row,next_col);
            if ( moves == -1 )
                return -1;
            steps += moves;
            sr = next_row;
            sc = next_col;
        }
                      
        return steps;
    }
    
    // return the minimum steps it takes to transition from a source position to a destination position
    int bfs( const vector<vector<int>> &forest, int sr, int sc, int tr, int tc )
    {
        if ( sr == tr && sc == tc )
            return 0;
        int Nr = forest.size(), Nc = forest[0].size();
        vector<vector<bool>> visited(Nr, vector<bool>(Nc,false));
        queue<pair<int,int> > q;
        q.push({sr,sc});
        int steps = 0;
        while ( !q.empty() )
        {
            steps++;
            for ( int i = q.size(); i >= 0; i-- )
            {
                auto cur_pos = q.front();
                q.pop();
                if ( cur_pos.first - 1 >= 0 && !visited[cur_pos.first-1][cur_pos.second] && forest[cur_pos.first-1][cur_pos.second] != 0 )
                {
                    if ( cur_pos.first - 1 == tr && cur_pos.second == tc )
                        return steps;
                    visited[cur_pos.first-1][cur_pos.second] = true;
                    q.push({cur_pos.first-1,cur_pos.second});
                }
                if ( cur_pos.first + 1 < Nr && !visited[cur_pos.first+1][cur_pos.second] && forest[cur_pos.first+1][cur_pos.second] != 0 )
                {
                    if ( cur_pos.first + 1 == tr && cur_pos.second == tc )
                        return steps;
                    visited[cur_pos.first+1][cur_pos.second] = true;
                    q.push({cur_pos.first+1,cur_pos.second});
                }
                if ( cur_pos.second - 1 >= 0 && !visited[cur_pos.first][cur_pos.second-1] &&  forest[cur_pos.first][cur_pos.second-1] != 0 )
                {
                    if ( cur_pos.first == tr && cur_pos.second - 1 == tc )
                        return steps;
                    visited[cur_pos.first][cur_pos.second-1] = true;
                    q.push({cur_pos.first,cur_pos.second-1});
                }
                if ( cur_pos.second + 1 < Nc && !visited[cur_pos.first][cur_pos.second+1] &&  forest[cur_pos.first][cur_pos.second+1] != 0 )
                {
                    if ( cur_pos.first == tr && cur_pos.second + 1 == tc )
                        return steps;
                    visited[cur_pos.first][cur_pos.second+1] = true;
                    q.push({cur_pos.first,cur_pos.second+1});
                }
                
            }
        }
        
        return -1;
    }
};

#endif 


class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int> > pos; 
        int m = forest.size(), n = forest[0].size(), sr = 0, sc = 0, steps = 0;
        for ( int r = 0; r < m; r++ )
            for ( int c = 0;  c < n; c++ )
            {
                if ( forest[r][c] > 1 )
                    pos.push_back({forest[r][c],r,c});
            }
        sort( pos.begin(), pos.end() );
        
        for ( int i = 0; i < pos.size(); i++ )
        {
            int moves = bfs_helper( forest, sr, sc, pos[i][1], pos[i][2] );
            if ( moves == -1 )
                return -1;
            steps += moves;
            sr = pos[i][1];
            sc = pos[i][2];
        }
        
        return steps;
    }
    
    int bfs_helper( const vector<vector<int>> &forest, int sr, int sc, int tr, int tc )
    {
        int steps = 0, m = forest.size(), n = forest[0].size();
        queue<pair<int,int>> pos;
        if ( sr == tr && sc == tc )
            return 0;
        pos.push({sr,sc});
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false) );
        while ( !pos.empty() )
        {
            steps++;
            for ( int i = pos.size(); i > 0; i-- )
            {
                auto cur = pos.front();
                pos.pop();
                for ( int k = 0; k < dir.size(); k++ )
                {
                    int r = cur.first + dir[k][0];
                    int c = cur.second + dir[k][1];
                    if ( r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || forest[r][c] == 0 )
                        continue;
                    if ( r == tr && c == tc )
                        return steps;
                    visited[r][c] = true;
                    pos.push({r,c});
                }
            }
        }
        
        return -1;
    }
}; 

int main()
{
    vector<vector<int> > trees = {{1,2,3},{0,0,0},{7,6,5}};
    Solution s;
    s.cutOffTree(trees);
}