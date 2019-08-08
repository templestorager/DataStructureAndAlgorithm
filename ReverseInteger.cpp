// Problem Description
/*
    Given a 32-bit signed integer, reverse digits of an integer.

    Example 1:

    Input: 123
    Output: 321
    Example 2:

    Input: -123
    Output: -321
    Example 3:

    Input: 120
    Output: 21
    Note:
    Assume we are dealing with an environment which could only store integers within the 32-bit 
    signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your 
    function returns 0 when the reversed integer overflows.
 * 
 */

// hint: check the overflow 
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while ( x != 0 ) {
            int rem = x % 10;
            if ( rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7) ) 
                return 0;
            if ( rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8) )
                return 0;
            rev = rev * 10 + rem;
            x /= 10;
        }
        
        return rev;
    }
};