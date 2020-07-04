// Problem Description
/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/

// This is the straightforward solution 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 )
            return false;
        while ( n % 2 == 0 )
            n /= 2;
        return n == 1;
    }
};

// Leverage the two's-complementary representation 
// Two's-complementary is used to store negative number, which flips all bits and then add 1 to the result
// The end result it reverts all bits except the rightmost 1. Therefore, if the number is a power of two, then 
// n & -n should be equal to n.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 )
            return false;
        return (n & -n) == n;
    }
};

// it could also leverage the fact that if an int minus one is change all training 0 to 1 and flip the righmost 1 to 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 )
            return false;
        return (n & n-1) == 0;
    }
};