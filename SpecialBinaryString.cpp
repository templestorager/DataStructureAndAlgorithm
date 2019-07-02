// Problem Description 
/*
* Special binary strings are binary strings with the following two properties:
* The number of 0's is equal to the number of 1's.
* Every prefix of the binary string has at least as many 1's as 0's.
* Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings 
* of S, and swapping them. (Two strings are consecutive if the last character of the first string is 
* exactly one index before the first character of the second string.)
* At the end of any number of moves, what is the lexicographically largest resulting string possible?

* Example 1:
* Input: S = "11011000"
* Output: "11100100"
* Explanation:
* The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
* This is the lexicographically largest string possible after some number of swaps.
*/

// Idea: 
// The key point is to understand the approach to construct valid special binary string
// Then we need to recursively obtain all valid special binary strings and concatenate them 
// in the sorted order to form the largest string value
class Solution {
public:
    string makeLargestSpecial(string S) {
        int ParenthesePairs = 0, i = 0;
        vector<string> validSBS;
        string res("");
        for ( int j = 0; j < S.size(); ++j ) {
            ParenthesePairs  += (S[j] == '1') ? 1 : -1;
            if  ( ParenthesePairs == 0 ) {
                validSBS.push_back('1' +  makeLargestSpecial(S.substr(i+1,j-i-1)) + '0' );
                i = j + 1;
            }
        }
        sort(validSBS.begin(),validSBS.end(),greater<string>());
        for( int i = 0; i < validSBS.size(); i++ )
            res += validSBS[i];
        return res;
    }
};