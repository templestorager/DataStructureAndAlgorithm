// Problem Description 
/*
 * Given a string s, find the longest palindromic substring in s. You may assume that
 *  the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 */

/* 
 * Methods: 
 * 1. Brute force. Check each possible substring whether it is a palindromic string or not 
 * 2. Dynamic programming
 * 3. Check each substring which centers around a given element. Need to consider the checke subsring 
 *    could have old or even length. 
 * 4. Manacher's Algorithm 
 */


// this solution checks each substring with a given index as its center and then expands to 
// find palindromic strings. 
// Time complexity O(n^2), space complexitity O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if( s.size() < 1  )
            return "";
        int start = 0, end = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            int len = max(len1,len2);
            if ( len > end - start ) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
    
private:
    int expandAroundCenter(string s, int left, int right ) {
        while ( left >=0 && right < s.size() && s[left] == s[right] ) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

// This solutions uses dynamic programming 
// Time complexity O(n^2), space complexity O(n^2)
// IsPalindromic[j][i] indicates whether s[j]..s[i] is palindromic or not 

class Solution {
public:
    string longestPalindrome(string s) {
        if( s.empty() )
            return "";
        int IsPalindromic[s.size()][s.size()] = {0};
        int left = 0, right = 0, len = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            IsPalindromic[i][i] = 1;
            for ( int j = 0; j < i; j++ ) {
                IsPalindromic[j][i] = ( s[i] == s[j] && ( i - j < 2 || IsPalindromic[j+1][i-1]));
                if ( IsPalindromic[j][i] && len < i - j + 1 ) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
        }
        return s.substr(left,right - left +1);
    }
};

// The same idea of expanding around center, but doesn't use function calls 
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0, start = 0, n = s.size();
        if ( n < 2 )
            return s;
        for ( int i = 0; i < n;)
        {
            if ( n-i <= maxlen / 2 )
                break;
            int l = i, r = i;
            while ( r < n - 1 && s[r+1] == s[r] ) 
                r++;
            i = r + 1;
            while ( r < n - 1 && l > 0 && s[r+1] == s[l-1] )
            {
                r++;
                l--;
            }
            if ( maxlen < r - l + 1 )
            {
                maxlen = r - l + 1;
                start = l;
            }
        }
        
        return s.substr(start, maxlen);
    }
};

// This solution uses the Manacher's algorithm 

// https://www.hackerrank.com/topics/manachers-algorithm