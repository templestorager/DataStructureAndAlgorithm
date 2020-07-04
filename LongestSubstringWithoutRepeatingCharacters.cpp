// Problem Description
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// We use a map to maitain the position of the chars currently in the sliding window 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, len =0;
        vector<int> m(128,-1);
        for ( int i = 0; i < s.size(); i++ )
        {
            left = max( left, m[s[i]] );   
            len = max( len, i-left );
            m[s[i]] = i;
        }
        
        return len;
    }
};

// The same as the above solution, but using a map structure. 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, len =0;
        unordered_map<char,int> m;
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( m.count(s[i]) && m[s[i]] > left )
            {
                left = m[s[i]];
            }
            len = max( len, i-left );
            m[s[i]] = i;
        }      
        return len;
    }
};