// Problem Description 
/*
 Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.
 */

// different from hard question version which requires to find every possible valid expression afer removals 
// this question requires to find only one. Therefore, we can find one solution by finding the unmatched parentheses 
// through using a stack and remember the indices needing to be removed in a set. 
// Finally, we iterate through the original string to remove those identifed chars. 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> left, right;
        string res;
        FindOneInvalidParenthese( s, left, right );
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( !left.count(i) && !right.count(i) )
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
    
    // This helper function calculates the indices of the invalid left and right parentheses of the string 
    // Note: it just finds one possibility, while there are many other possibilities 
    
    void FindOneInvalidParenthese( const string s, unordered_set<int> &left, unordered_set<int> &right )
    {
        stack<int> curopen;
        for ( int i = 0; i < s.size(); i++ )
        {
            switch (s[i])
            {
                case '(':
                    {
                        curopen.push(i);
                        break;
                    }
                case ')':
                    {
                        if ( curopen.empty() )
                        {
                            right.insert(i);
                        }
                        else 
                        {
                            curopen.pop();
                        }
                        break;
                    }
            }
        }
        
        while ( !curopen.empty() )
        {
            int top = curopen.top();
            curopen.pop();
            left.insert(top);
        }
    }
};

// This solution uses two parses. In the first pass, we remove all invalid ')', while remembering 
// how many pairs of '(' and ')', which is the balance in the end res. 
// Then we remove all right-most '(' after balance '('. 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance;
        FindInvalidParenthese( s, balance);
        string res;
        int i = 0;
        while ( balance )
        {
            if ( s[i] == '(' )
                balance--;
            res.push_back(s[i++]);
        }
        
        for ( ; i < s.size(); i++ )
        {
            if ( s[i] != '(' )
                res.push_back(s[i]);
        }
        
        return res;
    }
    
    // This helper function calculates the indices of the invalid left and right parentheses of the string 
    // Note: it just finds one possibility, while there are many other possibilities 
    
    void FindInvalidParenthese( string &s, int &final_bal )
    {
        int open = 0, close = 0, bal = 0;
        string res;
        for ( auto c : s )
        {
            bool remove = false;
            switch ( c )
            {
                case '(':
                    open++;
                    break;
                case ')':
                    if ( open > 0 )
                    {
                        open--;
                        bal++;
                    }
                    else 
                    {
                        remove = true;
                    }
            }
            
            if ( !remove )
                res.push_back(c);
        }
        
        s.clear();
        s = res;
        final_bal = bal;
    }
};

// The same idea the above solution. 
// Two steps:
// 1. Remove all invalid ')'
// 2. Remove the excessive '(' starting from the right-most if there is any.
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res_no_invalid_close, res; 
        int open = 0;
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( s[i] == '(' )
                open++;
            else if ( s[i] == ')' )
            {
                if ( open == 0 )
                    continue;
                open--;
            }
            res_no_invalid_close.push_back(s[i]);
        }
        
        // open is the amount of redundant right-most opens that needs to be removed
        for ( int i = res_no_invalid_close.size() - 1; i >= 0; i-- )
        {
            if ( res_no_invalid_close[i] == '(' && open-- > 0 )
                continue;
            res.push_back(res_no_invalid_close[i]);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};