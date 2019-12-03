// Problem Description 
/*
    Balanced strings are those who have equal quantity of 'L' and 'R' characters.

    Given a balanced string s split it in the maximum amount of balanced strings.

    Return the maximum amount of splitted balanced strings.

    Example 1:

    Input: s = "RLRRLLRLRL"
    Output: 4
    Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
    Example 2:

    Input: s = "RLLLLRRRLR"
    Output: 3
    Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
    Example 3:

    Input: s = "LLLLRRRR"
    Output: 1
    Explanation: s can be split into "LLLLRRRR".
    

    Constraints:

    1 <= s.length <= 1000
    s[i] = 'L' or 'R'
 * 
 * 
 */

// Similar to the parenthese matching problem, using greedy approach
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, curL = 0;
        for ( char c : s ) {
            if ( c == 'L' ) 
                curL++;
            else 
                curL--;
            if ( curL == 0 ) {
                curL = 0;
                res++;
            }
        }
        
        return res;
    }
};