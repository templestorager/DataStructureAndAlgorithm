// Problem Description
/*
 
    Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

    Example 1:
    Input: "aba"
    Output: True
    Example 2:
    Input: "abca"
    Output: True
    Explanation: You could delete the character 'c'.
    Note:
    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

// slight change to the validpalindrome problem, i.e., if a mismatch is found, then we skip either of the mismatched character.
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while( i < j )
        {
            if ( s[i] == s[j] )
            {
                i++;
                j--;
            }
            else if ( helper(s,i+1,j) || helper(s,i,j-1) )
            {
                return true;
            } 
            else 
            {
                return false;
            }
        }
        return true;
    }
    bool helper(string s, int l, int r )
    {
        while( l < r )
        {
            if ( s[l] == s[r] ) 
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};