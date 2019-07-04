// Problem Description 
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for ( int row = 0; row < numRows; row++ ) {
            res[row].resize(row+1,1);
            for ( int j = 1; j < row-1; j++ ) {
                res[row][j] = res[row-1][j-1] + res[row-1][j];
            }
        }
        return res;
    }
};