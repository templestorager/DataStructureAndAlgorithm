// Problem Description
/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

// this method maintains the status of the chars in a sliding window
// when the sliding window contains all the characters in string t, we need to try to 
// strip off the begining characters which are not in the string t. 

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> remainingcharset;
        string res;
        int left = 0, runlen = 0, slen = s.size(), tlen = t.size(), minlen = INT_MAX;
        for ( auto ch : t ) 
        {
            remainingcharset[ch]++;
        }
        
        for ( int i = 0; i < slen; i++ )
        {
            if ( --remainingcharset[s[i]] >= 0 )
                runlen++;
            while ( runlen == tlen )
            {
                if ( minlen > i - left + 1 )
                {
                    minlen = i-left+1;
                    res = s.substr(left,minlen);
                }
                if ( ++remainingcharset[s[left]] > 0 )  // if s[left] is not in t, the value would be zero 
                    --runlen;
                ++left;
            }
        }
        
        return res;
    }
};