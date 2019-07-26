// Problem Description 
/*
 * Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new 
 * string.

    Example 1:

    Input: "leetcodeisacommunityforcoders"
    Output: "ltcdscmmntyfrcdrs"
    Example 2:

    Input: "aeiou"
    Output: ""
 * 
 */

// This solution uses an auxiliary string to hold res and as we check the chars, we put the non-vowels
// in the res.
// O(n), O(n)
class Solution {
public:
    string removeVowels(string S) {
        set<char> vowels{{'a','e','i','o','u','A','E','I','O','U'}};
        int len = S.size();
        int newlen = 0;
        string newstring(len,'\0');
        for ( int i = 0; i < len; i++ )  {
            if ( !vowels.count(S[i]) ) {
                newstring[newlen++] = S[i];
            }
        }
        return newstring;
    }
};

// This solution uses the handy "remove_if" function, which removes the elements statisfying 
// the given predicate condition and returns the new end (position past the last element)
// O(n), O(1)
class Solution {
public:
    string removeVowels(string S) {
        auto to_erase = remove_if(S.begin(),S.end(),IsVowel);
        S.erase(to_erase,S.end());
        return S;
    }
    // Have to be static for the above use case ?? 
    static bool IsVowel(char ch) {
        set<char> vowels{{'a','e','i','o','u','A','E','I','O','U'}};
        return vowels.count(ch);
    }
};

// This solution is actually implementing the "remove_if" function 
// O(n),O(1)
class Solution {
public:
    string removeVowels(string S) {
        set<char> vowels{{'a','e','i','o','u','A','E','I','O','U'}};
        int nonvowels = 0;
        for ( int i = 0; i < S.size(); i++ ) {
            if ( !vowels.count(S[i]) ) {
                S[nonvowels++] = S[i];
            }
        }
        S[nonvowels] = '\0';
        return S;
    }
};