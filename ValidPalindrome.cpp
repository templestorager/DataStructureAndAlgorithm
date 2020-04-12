// Problem Description
/*
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: For the purpose of this problem, we define empty string as valid palindrome.

    Example 1:

    Input: "A man, a plan, a canal: Panama"
    Output: true
    Example 2:

    Input: "race a car"
    Output: false
*/

// Idea: use a stack to reversely store legitimate chars and then compare them in sequence 
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( isalnum(s[i]) )
            {
                st.push(toupper(s[i]));
            }
        }
        
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( !isalnum(s[i]) )
                continue;
            if ( toupper(s[i]) != st.top() )
                return false;
            st.pop();
        }
                
        return true;
    }
};

// Simiar idea, but use two pointers 
class Solution {
public:
    bool isPalindrome(string s) {
        if ( s.empty() )
            return true;
        int i = 0, j = s.size() - 1;
        while ( i < j )
        {
            while ( (i < j ) && !isalnum(s[i]) ) i++;
            while ( (i < j ) && !isalnum(s[j]) ) j--;
            if ( (i < j ) && toupper(s[i]) != toupper(s[j]) )
                return false;
            i++;
            j--;
        }
        return true;
    }
};