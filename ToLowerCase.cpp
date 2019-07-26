// Problem Description 
/*
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string 
 * in lowercase.
    Example 1:

    Input: "Hello"
    Output: "hello"
    Example 2:

    Input: "here"
    Output: "here"
    Example 3:

    Input: "LOVELY"
    Output: "lovely"
 * 
 */

// Use the transform function 
// O(n), O(1)
class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(),str.end(),str.begin(),[](const char ch ){ return tolower(ch);});
        return str;
    }
};

class Solution {
public:
    string toLowerCase(string str) {
        for ( int i = 0; i < str.size(); i++ ) {
            if ( str[i] >= 'A' && str[i] <= 'Z' ) {
                str[i] = 'a' + str[i] - 'A';
            }
        }   
        return str;
    }
};