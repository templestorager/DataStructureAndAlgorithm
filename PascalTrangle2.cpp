// Problem Description 
/*
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 */
// O(k), O(k)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for ( int row = 1; row <= rowIndex; row++ ) {
            for ( int col = row; col >= 1; --col ) {
                res[col] += res[col-1];
            }
        }
        return res;
    }
};