// Problem Description 
/*
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be 
 * used once).
 * 
 * Return the sum of lengths of all good strings in words.
 * Example 1:

    Input: words = ["cat","bt","hat","tree"], chars = "atach"
    Output: 6
    Explanation: 
    The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
    Example 2:

    Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    Output: 10
    Explanation: 
    The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
    

    Note:

    1 <= words.length <= 1000
    1 <= words[i].length, chars.length <= 100
    All strings contain lowercase English letters only.

 * 
 */

// straightforward to use map 
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> charmap;
        int len = 0;
        for ( auto ch : chars ) {
            charmap[ch]++;
        }
        for ( auto word : words ) {
            if ( IsFormed(word,charmap) )
                len += word.size();
        }
        
        return len;
    }
    
private:
    bool IsFormed( const string str, const map<char,int> charmap )
    {
        set<char> strmap; 
        map<char,int> m = charmap;
        bool result = true; 
        for ( auto ch : str ) {
            if ( m[ch] > 0 ) {
                m[ch]--;
            }
            else {
                result = false;
                break;
            }
        }
        
        return result;
    }
};