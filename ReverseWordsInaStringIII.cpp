// Problem Description 
/*
 * Given a string, you need to reverse the order of characters in each word within a sentence 
 * while still preserving whitespace and initial word order.

    Example 1:
    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"
    Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 * 
 * 
 */

class Solution {
public:
    string reverseWords(string s) {
        int word_begin, word_end;
        for ( word_begin = 0; word_begin < s.size(); word_begin = word_end) {
            while ( s[word_begin] == ' ' ) 
                word_begin++;
            word_end = word_begin;
            while ( s[word_end] != ' ' && s[word_end] != '\0' ) 
                word_end++;
            reverse(s.begin()+word_begin,s.begin()+word_end);
        }
        
        return s;
    }
};