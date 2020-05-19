// Problem Description 
/*
 * Write a function that reverses a string. The input string is given as an array of characters 
 * char[]. Do not allocate extra space for another array, you must do this by modifying the input 
 * array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii characters.
    Example 1:

    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
    Example 2:

    Input: ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]
 *
 * */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for ( int i = 0; i < len/2; i++ ) {
            swap(s[i],s[len-i-1]);
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> res(s);
        for ( int i = s.size() - 1, j = 0; i >= 0; i-- ) {
            res[j++] = s[i];
        }
        s = res;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

// C-language version 
void reverseString(char* s, int sSize){
    char *end = &s[sSize-1];
    while( s < end )
    {
        char tmp = *s;
        *s++ = *end;
        *end-- = tmp;
    }
}