// Problem Description
/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/


// First we ensure s is shorter or equal to t 
// Then we find the first difference. 
// If there exist such a difference, then the remaining substring of s must be the same as that of t 
// or the difference char is an extra char in t. 
// Finally, if we there is no difference, then t must have one more last char than s. 
// Otherwise, it's not one distance 
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // assume s shorter or equal to t, otherwise we swap them by calling the function 
        if ( s.length() > t.length() )
           return  isOneEditDistance( t, s );
        // Find the first difference i, and then it must be the remaining substrings are the same
        // or the difference char is an extra char 
        for ( int i = 0; i < s.length(); i++ )
        {
            if ( s[i] != t[i] )
            {
                return s.substr(i+1) == t.substr(i+1) || s.substr(i) == t.substr(i+1);
            }
        }
        
        return t.length() - s.length() == 1;
    }
};