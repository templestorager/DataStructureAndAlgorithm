// Problem Description
/*
    Given an array A of non-negative integers, half of the integers in A are odd, and half of the 
    integers are even. Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] 
    is even, i is even.

    You may return any answer array that satisfies this condition.

    Example 1:
    Input: [4,2,5,7]
    Output: [4,5,2,7]
    Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

    Note:

    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000
 * 
 */

// check each number and put it in the appropriate position according to the requirement 
// O(n), O(n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> res(n,0);
        if ( n == 2 ) {
            if ( A[0] % 2 != 0 )
                swap( A[0], A[1] );
        }
        
        int evenidx = 0, oddidx = 1;
        for ( int next = 0; next < n; next++ ) {
            if ( A[next] % 2 ) {
                res[oddidx] = A[next];
                oddidx += 2;
            } else {
                res[evenidx] = A[next];
                evenidx += 2;
            }
        }
        
        return res;
    }
};

// in-place solution, if an element is not in place, we find a replacement and swap 
// O(n), O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddidx = 1;
        for ( int i = 0; i < A.size(); i += 2 ) {
            if ( A[i] % 2 ) {
                while ( A[oddidx] % 2 ) {
                    oddidx += 2;
                }             
                swap(A[i],A[oddidx]);          
            }
        }
        return A;
    }
};