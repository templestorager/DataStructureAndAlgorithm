// Problem Description 
/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is
 * surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
    Example 1:

    Input:
    11110
    11010
    11000
    00000

    Output: 1
    Example 2:

    Input:
    11000
    11000
    00100
    00011

    Output: 3
 *  
 */

// This solution uses dfs to mark islands as '0', then count the number of '1's
// O(MxN), O(MxN) worst case 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.size() == 0 || grid[0].size() == 0 )
            return 0;
        int nr = grid.size();
        int nc = grid[0].size();
        int res = 0;
        for ( int r = 0; r < nr; r++ ) {
            for ( int c = 0; c < nc; c++ )  {
                if ( grid[r][c] == '1' ) { 
                    res++;
                    dfs(grid,r,c);
                }
            }
        }
        return res;
    }
    
    void dfs( vector<vector<char>>& grid, int row, int col ) {
        int nr = grid.size();
        int nc = grid[0].size();
        
        if ( row < 0 || col < 0 || row >= nr || col >= nc || grid[row][col] == '0' ) 
            return ;
    
        grid[row][col] = '0';
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
};

// This solution uses bfs 
// O(MxN), O(min(M,N))
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if ( !nr )
            return 0;
        int nc = grid[0].size();
        
        int num_islands = 0;
        for ( int r = 0; r < nr; r++ )  {
            for ( int c = 0; c < nc; c++ ) {
                if ( grid[r][c] == '1' ) { 
                    num_islands++;
                    grid[r][c] = '0';
                    queue<pair<int,int>> neighbors;
                    neighbors.push({r,c});
                    while ( !neighbors.empty() ) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if ( row - 1 >= 0 && grid[row-1][col] == '1' ) {
                            neighbors.push({row-1,col});
                            grid[row-1][col] = '0';
                        }
                        if ( row + 1 < nr && grid[row+1][col] == '1' ) {
                            neighbors.push({row+1,col});
                            grid[row+1][col] = '0';
                        }
                        if ( col - 1 >=0 && grid[row][col-1] == '1' ) {
                            neighbors.push({row,col-1});
                            grid[row][col-1] = '0';
                        }
                        if ( col + 1 < nc && grid[row][col+1] == '1' ) {
                            neighbors.push({row,col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};