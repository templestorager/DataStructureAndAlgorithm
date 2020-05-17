// Problem Description
/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

// bottom-up dynamic programming 
// O(n), O(n)
class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 1 )
            return 1;
        vector<int> memo(n+1);
        memo[1] = 1;
        memo[2] = 2;
        for( int i = 3; i <=n; i++ )
            memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};

// top-down dynamic programming, recurision with memoization 
// O(n), O(n)
class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 1 )
            return 1;
        vector<int> mem(n+1);
        mem[1] = 1;
        mem[2] = 2;
        return climb_stair(n,mem);
    }
    int climb_stair( int n, vector<int> &mem )
    {
        if ( mem[n] != 0 )
            return mem[n];
        mem[n] = climb_stair(n-1,mem) + climb_stair(n-2,mem);
        
        return mem[n];
        
    }
};

// The iterative Fibonacci method 
// O(n), O(1)
class Solution {
public:
    int climbStairs(int n) {
        if ( n == 1 )
            return 1;
        int first = 1, second = 2;
        for ( int i = 3; i <= n; i++ )
        {
            int third = first+second;
            first = second;
            second = third;
        }
        
        return second;
    }
};

// The follwing method is purely based on math, which use the general formula of the nth number of 
// Fibonacci sequence. 
// 
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        return (1/sqrt5) * (pow((1+sqrt5)/2,n+1) - pow((1-sqrt5)/2,n+1) );
    }
};

// This solution uses the divide-and-conquer approach. 
// So we consider the middle of the stairs, we could either step on it (choose 1 at stair middle-1) or step over it (choose 2 at stair middle - 1 ). 
class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 1 )
            return 1;
        return climbStairs(n/2) * climbStairs(n-n/2) + climbStairs(n/2-1)*climbStairs(n-n/2-1);
    }
};