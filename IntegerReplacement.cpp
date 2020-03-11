// Problem Description
/*
 Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

// This is the straightforward recursive alogrithm.
// However, this algorithm would run into stack overflow for larger numbers 
class Solution {
public:
    int integerReplacement(int n) {
        if ( n == 1 ) 
            return 0;
        if ( n & 1 == 0 ) 
            return integerReplacement(n/2) + 1;
        else 
            return min( integerReplacement(n+1), integerReplacement(n-1)) + 1;
    }
};


// This solution is based on the intuition that we want as many trailing zero as possible
// If the number is even, then we have no choice but to halve the value.
// If the number is odd, then if the second to the last is zero, we decrement the value since doing 
// so results in two trailing zeros (*01-->*00). 
// If the second to the last is 1, then we increment the value for the same reason (*11-->*00), 
// except when the number is three, for which we decrement (11->10->1 instead of 11->100->10-1)
class Solution {
public:
    int integerReplacement(int n) {
        int steps = 0; 
        if ( n == INT_MAX )
            return 32;
        while ( n > 1 )
        {
            if ( (n & 1) == 0 )
            {
                n >>= 1;
            }
            else 
            {
                if ( n & 2 && n != 3 )
                    n++;
                else 
                    n--;
            }
            steps++;
        }
        
        return steps;
    }
};