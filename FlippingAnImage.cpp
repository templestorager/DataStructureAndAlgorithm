// Problem Description 
/*
 * 
    Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

    To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

    To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

    Example 1:

    Input: [[1,1,0],[1,0,1],[0,0,0]]
    Output: [[1,0,0],[0,1,0],[1,1,1]]
    Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
    Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
    Example 2:

    Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
    Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
    Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
    Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
    Notes:

    1 <= A.length = A[0].length <= 20
    0 <= A[i][j] <= 1
 * 
 */

// hint: straightforward to swap the row and negate each value 
// pay special attention to negate the middle value hen n is odd, as the mid value was not swapped and negated
// alternatively we can make a pseudo swap, the mid swap with itself, by increase the internal loop condition to 
// (n+1)/2 ( we need to use the normal swap statements)
// O(n), O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n/2; j++ ) {
                swap(A[i][j],A[i][n-j-1]);
                A[i][j] = !A[i][j];
                A[i][n-j-1] = !A[i][n-j-1];
            }
            if ( n % 2 ) 
                A[i][n/2] = !A[i][n/2];
        }
        
        return A;
    }
};