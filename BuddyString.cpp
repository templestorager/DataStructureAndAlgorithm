// Problem Description
/*
 Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
 */

// Idea: need to meet three cases:
// 1. length is equal 
// 2. if equal, then there must be at least one duplicate char 
// 3. if not equal, then there are only two different positions 
class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> diff;
        if ( A.size() != B.size() || A.size() < 2 )
            return false;
        if ( A != B )
        {
            for ( int i = 0; i < A.size(); i++ )
            {
                if ( A[i] != B[i] )
                    diff.push_back(i);
            }
            return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
        }
        else // if A == B, then there must be duplicate char in the string 
        {
            return unordered_set<char>(A.begin(),A.end()).size() < A.size();
        }
    }
};