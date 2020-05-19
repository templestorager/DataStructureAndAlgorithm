// Problem Description 
/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/

// This is a classical DP problem in the text book. Please refer to the textbook.
// Basically, there are m*n subproblems
// An optimization would be just use to columns, noticing that we calculate every step by using only the current column and the previous column 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if ( m == 0 || n == 0 )
            return 0;
        int dp[m+1][n+1];
        memset( dp, 0, sizeof(dp) );
        for ( int r = 0; r < m; r++ )
            for ( int c = 0; c < n; c++ )
            {
                if ( text1[r] == text2[c] )
                {
                    dp[r+1][c+1] = dp[r][c] + 1;
                }
                else 
                {
                    dp[r+1][c+1] = max(dp[r+1][c], dp[r][c+1]);
                }
            }
        
        return dp[m][n];
    }
};