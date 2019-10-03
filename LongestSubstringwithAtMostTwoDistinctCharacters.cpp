// Problem Description
/*
    Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

    Example 1:

    Input: "eceba"
    Output: 3
    Explanation: t is "ece" which its length is 3.
    Example 2:

    Input: "ccaabbb"
    Output: 5
    Explanation: t is "aabbb" which its length is 5.
 */

// Sliding window method 
// We use a hashmap to store the chars in the sliding window 
// once the number of chars is more than, we need to remove the leftmost char
// O(n), O(n)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, erase_idx = 0;
        unordered_map<char,int> m;
        for ( int i = 0; i < s.size(); i++ ) {
            m[s[i]]++;
            while( m.size() > 2 ) {
                m[s[erase_idx]]--;
                if ( m[s[erase_idx]] == 0 ) 
                    m.erase(s[erase_idx]);
                erase_idx++;
            }
            res = max(res,i-erase_idx+1);
        }
        
        return res;
    }
};

// This solution is quite similar to the above solution 
// but it stores the positions of the chars in the hashmap 
// O(n), O(n)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, res = 0;
        unordered_map<char, int> m;
        for ( int i = 0; i < s.size(); i++ ) {
            m[s[i]] = i;
            while ( m.size() > 2 ) {
                if ( m[s[left]] == left ) 
                    m.erase(s[left]);
                left++;
            }
            res = max(res,i-left+1);
        }     
        return res;
    }
};

// This solution keeps the substring of unique letters s[left..right]
// O(n), O(1)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = -1, res = 0, n = s.size();
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) continue;
            if (right >= 0 && s[right] != s[i]) {
                res = max(res, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        res = max( res, n - left );
        return res;
    }
};

// this solution maintains several variables:
// The two distinct elements currently considered: firstch, secondch
// The cur lenght of the substring which has firstch and secondch: 
// The lenght of the last element (i.e., secondch)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if ( s.size() == 0 ) 
            return 0;
        int res = 0, curcnt = 0, secondcnt = 0;
        char firstch = '\0', secondch = '\0';
        for ( char c : s ) {
            curcnt = ( c == firstch || c == secondch ) ? curcnt + 1 : secondcnt + 1;
            secondcnt = ( c == secondch ) ? secondcnt + 1 : 1; 
            if ( c != secondch ) {
                firstch = secondch;
                secondch = c;
            }
            res = max ( res, curcnt );
        }
        
        return res;
    }
};