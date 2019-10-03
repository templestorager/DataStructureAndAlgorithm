// Problem Descrption
/*
 * 
    Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.

    Example 1:

    Input: A = [34,23,1,24,75,33,54,8], K = 60
    Output: 58
    Explanation: 
    We can use 34 and 24 to sum 58 which is less than 60.
    Example 2:

    Input: A = [10,20,30], K = 15
    Output: -1
    Explanation: 
    In this case it's not possible to get a pair sum less that 15.

    Note:

    1 <= A.length <= 100
    1 <= A[i] <= 1000
    1 <= K <= 2000

 */ 

// Brute force solution
// O(n^2), O(1)
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int r = -1;
        for (int i = 0; i < A.size(); ++ i) {
            for (int j = i + 1; j < A.size(); ++ j) {
                if (A[i] + A[j] < K) {
                    r = max(r, A[i] + A[j]);
                }
            }
        }
        return r;
    }
};


// Sort + two pointer
// O(nlgn), O(1)
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort( A.begin(), A.end() );
        int ans = INT_MIN;
        bool found = false;
        int b = 0, e = A.size() - 1;
        while ( b < e ) {
            if ( A[b] + A[e] >= K ) {
                e--;
            }
            else 
            {
                ans = max( ans, A[b]+A[e] );
                found = true;
                b++;
            }
        }
        if ( found )
            return ans;
        else 
            return -1;
    }
};