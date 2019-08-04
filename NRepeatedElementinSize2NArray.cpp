// Problem description 
/*
    In an array A of size 2N, there are N+1 unique elements, and exactly one of these elements is 
    repeated N times.
    Return the element repeated N times.

    Example 1:

    Input: [1,2,3,3]
    Output: 3
    Example 2:

    Input: [2,1,2,5,3,2]
    Output: 2
    Example 3:

    Input: [5,1,5,2,5,3,5,4]
    Output: 5
    
    Note:

    4 <= A.length <= 10000
    0 <= A[i] < 10000
    A.length is even
 * 
 */

// This solution uses a multiset to store values seen so far
// O(n), O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_multiset<int> valcountmap;
        int res; 
        for ( int i = 0; i < A.size(); i++ ) {
            if ( valcountmap.count(A[i]) )  {
                res = A[i];
                break;
            }
            valcountmap.insert(A[i]);
        }
        return res;
    }
};

// According to the pigeonhole principle, the N repeated numbers must be evenly distributed among 
// the other N unique numbers or have at least two adjcent positions
// O(n), O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for ( int i = 0; i< A.size()-1; i++ ) {
            if ( A[i] == A[i+1] ) 
                return A[i];
        }
        
        if ( A.size() == 0 ) 
            return -1;
        if ( A.size() <= 2 ) 
            return A[0];
        for ( int i = 0; i < 2; i++ ) {
            if  ( A[i] == A[A.size()-1] || A[i] == A[A.size()-2] ) 
                return A[i];
        }
        
        return -1;
    }
};