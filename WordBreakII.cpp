// Problem Description 
/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add 
 * spaces in s to construct a sentence where each word is a valid dictionary word. 
 * Return all such possible sentences.

    Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.
    Example 1:

    Input:
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    Output:
    [
    "cats and dog",
    "cat sand dog"
    ]
    Example 2:

    Input:
    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    Output:
    [
    "pine apple pen apple",
    "pineapple pen apple",
    "pine applepen apple"
    ]
    Explanation: Note that you are allowed to reuse a dictionary word.
    Example 3:

    Input:
    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output:
    []
 * 
 */

// O(n^3), O(n^3)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > memo;
        return wordBreakHelper(s,wordDict,memo);
    }
        
    vector<string> wordBreakHelper(string s,vector<string> wordDict,unordered_map<string,vector<string>> &memo) {
            if (memo.count(s))
                return memo[s];
            if ( s.empty() ) 
                return {""};
            vector<string> res;
            for ( string word : wordDict ) {
                if ( s.substr(0,word.size()) != word )
                    continue;
                vector<string> tail = wordBreakHelper(s.substr(word.size()),wordDict,memo);
                for ( string str : tail ) {
                    res.push_back(word + (str.empty() ? "" : " ") + str);
                }
            }
            return memo[s] = res;
        }
};