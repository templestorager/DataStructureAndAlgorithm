// Problem Description
/*
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

 
Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

// brute force solution: 
// check each pair of position (at least three) and then check the subsarray to see if it is a qualified slice 
// O(n^3)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int total_slices = 0;
        int n = A.size();
        if ( n < 2 )
            return 0;
        for ( int s = 0; s < n - 2; s++ )
        {
            int diff = A[s+1] - A[s];
            for ( int e = s + 2; e < n; e++ )
            {
                int i = 0;
                for ( i = s+1; i <= e; i++ )
                {
                    if ( A[i] - A[i-1] != diff ) 
                        break;
                }
                
                if ( i > e ) 
                    total_slices++;
            }
        }
        
        return total_slices;
    }
};

// We can improve over the above brute force approach a bit by noticing that if we know [s,e] is a slice 
// then to check [s,e+1], we just need to check the A[e+1] - A[e] and compare it with the previous difference, 
// if it is not equal to the previous difference, then we are done with all subarrays starting from @s, so we break 
// the inner loop
// O(n^2)
// O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int total_slices = 0;
        int n = A.size();
        if ( n < 2 )
            return 0;
        for ( int s = 0; s < n - 2; s++ )
        {
            int diff = A[s+1] - A[s];
            for ( int e = s + 2; e < n; e++ )
            {
                if ( A[e] - A[e-1]  == diff ) 
                    total_slices++;
                else 
                    break;
            }
        }
        
        return total_slices;
    }
};

// This solution uses recursive method 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        slices(A,A.size()-1,cnt);
        return cnt;
    }
    
    int slices(const vector<int> &A, int i, int &cnt ) 
    {
        if ( i < 2 ) 
            return 0;
        int ap = 0;
        if ( A[i] - A[i-1] == A[i-1] - A[i-2] )
        {
            ap = 1 + slices( A, i-1, cnt );
            cnt += ap;
        }
        else 
            slices(A,i-1,cnt);
        return ap;
    }
};

// This solution uses dynamic programming, as the number of (k,i+1) depends on (k,i)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), sum = 0;
        if ( n < 2 )
            return sum;
        int dp[n];
        memset(dp,0,sizeof(dp));

        for ( int i = 2; i < n; i++ )
        {
            if ( A[i] - A[i-1] == A[i-1] - A[i-2] )
            {
                dp[i] = 1+dp[i-1];
                sum += dp[i];
            }
        }
        
        return sum;
    }
};

// Like Fibonacci sequence, we can also use constance space 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), sum = 0;
        if ( n < 2 )
            return sum;
        int dp = 0;

        for ( int i = 2; i < n; i++ )
        {
            if ( A[i] - A[i-1] == A[i-1] - A[i-2] )
            {
                dp = 1+dp;
                sum += dp;
            }
            else 
                dp = 0;
        }
        
        return sum;
    }
};