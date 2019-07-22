// Problem Description 
/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 * 
 */

// This solution uses recursion with memorization 
// memo[i] means string[i..end] is valid 
// O(n^2), O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(),-1);
        return check(s,wordset,0,memo);
    }
    
    bool check(string s, const unordered_set<string> wordset, int start, vector<int> &memo ) {
        if ( start >= s.size() )
            return true;
        if ( memo[start] != -1 )
            return memo[start];
        for ( int i = start + 1; i <= s.size(); i++ ) {
            if ( wordset.count(s.substr(start,i-start)) && check(s,wordset,i,memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};

// This solution uses dynamic programming 
// dp[i] means whether s[0,i) is valid or not 
// O(n^2), O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for ( int i = 1; i <= dp.size(); i++ ) {
            for ( int j = 0; j < i;j++ ) {
                if ( dp[j] && wordset.count(s.substr(j,i-j))) { 
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

// This is BFS-base method 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<bool> visited(s.size());
        queue<int> q{{0}};
        while( !q.empty() ) {
            int start = q.front();
            q.pop();
            if ( !visited[start] ) { 
                for ( int i = start + 1; i <= s.size();i++ ) {
                    if ( wordset.count(s.substr(start,i-start))) {
                        q.push(i);
                        if ( i == s.size() ) 
                            return true;
                    }
                }
                visited[start] = true;
            }
        }
        return false;
    }
};