// Problem Description
/*
    Write a function that takes a string as input and reverse only the vowels of a string.

    Example 1:

    Input: "hello"
    Output: "holle"
    Example 2:

    Input: "leetcode"
    Output: "leotcede"
    Note:
    The vowels does not include the letter "y".
 * 
 */

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (1) {
            while(!IsVowel(s[i]) && i < j)
                i++;
            while(!IsVowel(s[j]) && j > i )
                j--;
            if ( i >= j ) 
                break;
            swap(s[i++],s[j--]);
        }
        return s;
    }
private:
    bool IsVowel( char ch ) {
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        return vowels.find(ch) != vowels.end();
    }
};