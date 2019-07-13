// Problem Description 
/*
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 */

// This solution sorts the two strings first. 
// O(nlgn), O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) 
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

// This solution uses hashing to record the characteristics of each string. 
// O(n), O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) 
            return false;
        int charset[26] = {0};
        for ( int i = 0; i < s.size(); i++ ) 
            charset[s[i]-'a']++;
        for ( int j = 0; j < t.size(); j++ ) 
            if ( --charset[t[j]-'a'] < 0 ) 
                return false;
        return true;
    }
};