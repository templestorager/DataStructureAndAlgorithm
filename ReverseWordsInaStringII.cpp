// Problem Description 
/*
 * Given an input string , reverse the string word by word. 

    Example:

    Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
    Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
    Note: 

    A word is defined as a sequence of non-space characters.
    The input string does not contain leading or trailing spaces.
    The words are always separated by a single space.
    Follow up: Could you do it in-place without allocating extra space?
 * 
 * 
 */

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        for ( int i = 0, j = 0; i < s.size(); i = j + 1 ) {
            for ( j = i; j < s.size(); j++ ) {
                if ( s[j] == ' ' )
                    break;
            }
            reverse(s.begin() + i, s.begin() + j);
        }
    }
};