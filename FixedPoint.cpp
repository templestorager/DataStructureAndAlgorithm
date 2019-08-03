// Problem Description
/*
 * Given an array A of distinct integers sorted in ascending order, return the smallest index i 
 * that satisfies A[i] == i.  Return -1 if no such i exists.

    Example 1:

    Input: [-10,-5,0,3,7]
    Output: 3
    Explanation: 
    For the given array, A[0] = -10, A[1] = -5, A[2] = 0, A[3] = 3, thus the output is 3.
    Example 2:

    Input: [0,2,5,8,17]
    Output: 0
    Explanation: 
    A[0] = 0, thus the output is 0
 * 
 */

// O(n), O(1)
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        for ( int i = 0; i < A.size(); i++ ) {
            if ( A[i] == i )
                return i;
        }
        
        return -1;
    }
};

// binary search
// O(lgn), O(1)
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int low = 0, high = A.size();
        int mid;
        bool found = false;
        while ( low < high ) {
            mid = low + ( high - low ) / 2;
            if ( A[mid] == mid ) {
                found = true;
                break;
            } else if ( A[mid] > mid ) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if ( !found ) 
            return -1;
        // handle the case where duplicates exist
        // Only look the left side as we need to find the smallest index 
        while ( mid > 0 ) {
            if ( A[mid-1] != mid - 1 ) {
                break;
            }
            mid--;
        }
        
        return mid;
    }
};