// Problem Description
/*
 
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
 */

// This straighforward method uses stacks to process each string to obtain the final string and then compare them directly 
// O(n), O(n)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        int i = 0, j = 0;
        while ( i < S.size() )
        {
            if ( S[i] != '#' )
                s.push(S[i]);
            else if ( !s.empty() )
                s.pop();
            i++;
        }
        while ( j < T.size() )
        {
            if ( T[j] != '#' )
                t.push(T[j]);
            else if ( !t.empty() )
                t.pop();
            j++;
        }
        while( !s.empty() && !t.empty() )
        {
            if ( s.top() != t.top() )
                return false;
            s.pop();
            t.pop();
        }
        
        return s.empty() && t.empty();
    }
};

// this method process the possible backspace in reverse order, because that has the authorative 
// answer about a char should be included in the final string or not
class Solution {
public:
bool backspaceCompare(string S, string T)  {
    int i = S.size() - 1, j = T.size() - 1;
    int numback1 = 0, numback2 = 0;
    while ( i >= 0 || j >= 0 )
    {
        while( i >= 0 && ( numback1 > 0 || S[i] == '#' ) )  // we need to skipp the current char if we have more backspace to cancel it or it is a backspace 
        {
            if ( S[i] == '#' )
                numback1++;
            else
                numback1--;
            i--;            // skip the current char 
            // S[i--] == '#' : numback1++ : numback1--;
        }
        while ( j >= 0 && (numback2 > 0 || T[j] == '#' ) )
        {
            if ( T[j] == '#' )
                numback2++;
            else
                numback2--;
            j--;
            // T[i--] == '#' : numback2++ : numback2--;
        }
        if ( i < 0 || j < 0 )       // if either one is depleted, then it's only true when both are depleted 
            return i == j;
        if ( S[i--] != T[j--] )     // otherwise, we check the next valid char 
            return false;
    }
    return i == j;
 }

};