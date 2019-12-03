// Problem Description
/*
    Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

    Example 1:
    Input:
    s = "abpcplea", d = ["ale","apple","monkey","plea"]

    Output: 
    "apple"
    Example 2:
    Input:
    s = "abpcplea", d = ["a","b","c"]

    Output: 
    "a"
    Note:
    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.

    Note:
    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.
 * 
 */

// This solution sorts the dictionary first (from longest to shortest and if equal len in lexicographical order )
// Then checks whether the word is a subsequence of the given string or not 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort( d.begin(), d.end(), [](string a, string b){if ( a.size() == b.size() ) return a < b; return a.size() > b.size(); });
        for ( string w : d ) {
            int i = 0; 
            for ( char c : s ) {
                if ( w[i] == c && i < w.size() ) 
                    i++;
            }
            
            if ( i == w.size() ) 
                return w;
        }
        
        return "";
    }
};


// The same idea as the above solution, but it requires no sorting 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for ( string w : d ) {
            int i = 0; 
            for ( char c : s ) {
                if ( c == w[i] && i < w.size() )
                    i++;
            }
            
            if ( i == w.size() ) {
                if ( w.size() > res.size() ) {
                    res = w;
                } 
                else if ( w.size() == res.size() ) {
                    res = w < res ? w : res;
                }
            }
        }
        
        return res;
    }
};