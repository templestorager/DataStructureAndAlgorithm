// Problem Description
/*
    On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

    Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

    Now we view the projection of these cubes onto the xy, yz, and zx planes.

    A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 

    Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

    Return the total area of all three projections.

    

    Example 1:

    Input: [[2]]
    Output: 5
    Example 2:

    Input: [[1,2],[3,4]]
    Output: 17
    Explanation: 
    Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

    Example 3:

    Input: [[1,0],[0,2]]
    Output: 8
    Example 4:

    Input: [[1,1,1],[1,0,1],[1,1,1]]
    Output: 14
    Example 5:

    Input: [[2,2,2],[2,1,2],[2,2,2]]
    Output: 21
    

    Note:

    1 <= grid.length = grid[0].length <= 50
    0 <= grid[i][j] <= 50
 * 
 */

// The key is to understand the projected area of each 2D projection 
// the area of xy is calculatd as following: 
//  --- the sum of the number of non-zero in each of the vector
// the area of xz is calculatd as following: 
//  --- the sum of the max value of each vector
// the area of yz is calculated as following:
//  --- the sum of the max value of the numbers at the same column position
//  --- i.e., max(grid[0][i],grid[1][i],grid[2][i], ect...) 

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
     
        int xy = 0, xz = 0, yz = 0;
        for ( int i = 0; i < grid.size(); i++ ) {
            int non_zero = 0;
            for ( int j = 0; j < grid[i].size(); j++ ) {
                if ( grid[i][j] ) 
                    non_zero++;
            }
            
            xy += non_zero;
        }
        for ( int i = 0; i < grid.size(); i++ ) {
            int max = grid[i][0];
            for ( int j = 1; j < grid[i].size(); j++ ) {
                if ( max < grid[i][j] )
                    max = grid[i][j];
            }
            xz += max;
        }
        
        for ( int i = 0; i < grid[0].size(); i++ ) {
            int max = grid[0][i];
            for ( int j = 1; j < grid.size(); j++ ) {
                if ( grid[j][i] > max ) 
                    max = grid[j][i];
            }
            yz += max;
        }
        
        return xy + xz + yz;
    }
};

// using one loop construct 
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int total_area = 0;
        for ( int i = 0; i < grid.size(); i++ ) {
            int best_row = 0, best_col = 0;
            for ( int j = 0; j < grid[0].size(); j++ ) {
                if ( grid[i][j] ) 
                    total_area++;
                if ( best_row < grid[i][j] ) 
                    best_row = grid[i][j];
                if ( best_col < grid[j][i] )
                    best_col = grid[j][i];
            }
                total_area += best_row + best_col;
        }
        
        return total_area;
    }
};