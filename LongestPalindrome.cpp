// Problem Description 
/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

// Basically we need to calculate the frequencies of each char. 
// For even numbered chars, we can use all of them to construct a palindrome. 
// but for odd numbered chars, we can need to use minus 1, but in then end we can have one odd char
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> cnt; 
        int len = 0;
        bool  has_odd = false;
        for ( auto c : s )
            cnt[c]++;
        for ( auto it : cnt )
        {
            len += it.second;
            if ( it.second % 2 )
            {
                len--;
                has_odd = true;
            }
        }
        
        return has_odd ? len+1 : len;
    }
};

// The same idea to calculate the count of odd numbered chars. 
// In then end, we can keep one odd char 
class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for ( char c = 'A'; c <= 'z'; c++ )
            odds += count(s.begin(),s.end(),c) & 1;
        return s.size() - max(0,odds-1);
    }
};

// Use a set to keep track of odd numbered chars
class Solution {
public:
    int longestPalindrome(string s) {
        set<char> oddchar;
        for ( auto c : s )
        {
            if ( oddchar.count(c) )
                oddchar.erase(c);
            else 
                oddchar.insert(c);
        }
        return s.size() - max(0,(int)oddchar.size()-1);
    }
};