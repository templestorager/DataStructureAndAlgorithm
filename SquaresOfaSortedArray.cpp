// Problem Description 
/*
    Given an array of integers A sorted in non-decreasing order, 
    return an array of the squares of each number, also in sorted non-decreasing order.
    Example 1:

    Input: [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Example 2:

    Input: [-7,-3,2,3,11]
    Output: [4,9,9,49,121]

    Note:

    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A is sorted in non-decreasing order.
 * 
 */

// hint: change negative numbers to positive
// then sort and square 
// O(nlgn) O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for ( int i = 0; i < A.size(); i++ ) {
            A[i] = abs(A[i]);
        }
        
        sort( A.begin(), A.end() );
        for ( int i = 0; i< A.size(); i++ ) {
            A[i] *= A[i];
        }
        
        return A;
    }
};

// the above solution works fine, but it fails to leverge the given non-decreasing order
// The following solution leverages this given property. 
// It uses two pointers to iterate through the negative and positive portion, respectively. 
// while traversing, it merges the two parts. 
// O(n), O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int negativeidx, positiveidx, residx = 0;
        vector<int> res;
        for ( positiveidx = 0; positiveidx < A.size(); positiveidx++ ) {
            if ( A[positiveidx] >= 0 ) 
                break;
        }
        negativeidx = positiveidx - 1;
        while ( negativeidx >= 0 && positiveidx < A.size() ) 
        {
            if ( A[negativeidx] * A[negativeidx] < A[positiveidx] * A[positiveidx] ) 
            {
                res.push_back(A[negativeidx] * A[negativeidx]);
                negativeidx--;
            } 
            else 
            {
                res.push_back(A[positiveidx] * A[positiveidx]);
                positiveidx++;
            }
        }
        
        while ( negativeidx >= 0 ) {
            res.push_back(A[negativeidx] * A[negativeidx]);
            negativeidx--;
        }
        while ( positiveidx < A.size() )  {
            res.push_back(A[positiveidx] * A[positiveidx]);
            positiveidx++;
        }
        
        return res;
    }
};

// Similar to the above solution, but uses stack to store the negative part 
// O(n) O(n) specifically O(m), where is the number of negative values. 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        stack<int> negativesum; 
        int i, residx;
        for ( i = 0; i < A.size(); i++ ) {
            if ( A[i] < 0 ) {
                negativesum.push(A[i]*A[i]);
            } else {
                break;
            }
        }
        
        for ( residx = 0; i < A.size(); i++ ) {
            while ( !negativesum.empty() ) {
                if ( A[i] * A[i] > negativesum.top() ) {
                    A[residx++] = negativesum.top();
                    negativesum.pop();
                } 
                else { 
                    A[residx++] = A[i] * A[i];
                    break;
                }
            }
            if ( negativesum.empty() ) {
                A[residx++] = A[i]*A[i];
            }
        }
        
        while ( !negativesum.empty() ) {
            A[residx++] = negativesum.top();
            negativesum.pop();
        }
        
        return A;
    }
};