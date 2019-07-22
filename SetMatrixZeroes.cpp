// Problem Description 
/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 * 
    Example 1:

    Input: 
    [
    [1,1,1],
    [1,0,1],
    [1,1,1]
    ]
    Output: 
    [
    [1,0,1],
    [0,0,0],
    [1,0,1]
    ]
    Example 2:

    Input: 
    [
    [0,1,2,0],
    [3,4,5,2],
    [1,3,1,5]
    ]
    Output: 
    [
    [0,0,0,0],
    [0,4,5,0],
    [0,3,1,0]
    ]
    Follow up:
        A straight forward solution using O(mn) space is probably a bad idea.
        A simple improvement uses O(m + n) space, but still not the best solution.
        Could you devise a constant space solution?
 * 
 */

// This solution uses additonal memory to first remember both rows and cols which have zero elements. 
// O(MxN), O(M+N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        set<int> rows;
        set<int> cols;
        for ( int row = 0; row < r; row++ ) {
            for ( int col = 0; col < c; col++ ) {
                if ( matrix[row][col] == 0 ) {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }
        
        for ( int row = 0; row < r; row++ ) {
            for ( int col = 0; col < c; col++ ) {
                if ( rows.count(row) || cols.count(col) ) 
                    matrix[row][col] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        int r = matrix.size();
        int c = matrix[0].size();
        for ( int i = 0; i < r; i++ ) {
            if ( matrix[i][0] == 0 ) {
                isCol = true;
            }
            
            for ( int j = 1; j < c; j++ ) {
                if ( matrix[i][j] == 0 ) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for ( int i = 1; i < r; i++ ) {
            for ( int j = 1; j < c; j++ ) {
                if ( matrix[i][0] == 0 || matrix[0][j] == 0 ) 
                    matrix[i][j] = 0;
            }
        }
        
        if ( matrix[0][0] == 0 ) {
            for ( int j = 1; j < c; j++ ) {
                matrix[0][j] = 0;
            }
        }
            
        if ( isCol ) {
            for ( int i = 0; i < r; i++ ) {
                matrix[i][0] = 0;
            }
        }
    }
};