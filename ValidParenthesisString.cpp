// Problem Description 
/*
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to 
 * check whether this string is valid. We define the validity of a string by these rules:
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 * An empty string is also valid.
 * 
 * Example 1:
 * Input: "()"
 * Output: True
 * 
 * Example 2:
 * Input: "(*)"
 * Output: True
 * 
 * Example 3:
 * Input: "(*))"
 * Output: True 
 * 
 */

// This solution uses stack to remember the opens (both '(' and '*')) as it checks the parenthesises.
// It records the index positions of '(' and '*' in the respective stacks, and consumes one open if a 
// close (')') is encountered. 
// After consuming all closing ')'s, it tries to pair '(' and '*', but we need to ensure the '(' must 
// come before '*', as '*(' is NOT valid. 
// Finally, if opens are all consumed, it is valid. 
// O(n) & O(n)
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        for ( int i = 0; i < s.size(); i++ ) {
            switch(s[i]) {
                case '(':
                    open.push(i);
                    break;
                case '*':
                    star.push(i);
                    break;
                case ')':
                    {
                        if ( open.empty() && star.empty() ) 
                            return false;
                        if ( !open.empty() )
                            open.pop();
                        else 
                            star.pop();
                    }
            }
        }
        while ( !open.empty() && !star.empty() ) {
            if ( open.top() > star.top() ) 
                return false;
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};

// This solution is interesting, as it requires two scans from opposite directions. 
// First, it scans from the left to right, treating every '*' an open('('). If anytime 
// open is less than close, it return false. If in the end, opens are all consumed, return true. 
// Otherwise, it means there are more opens than closes, but we are not sure the surplus opens are due to 
// real opens or stars being opens. If it is the latter case, then it is valid, since we could have used those 
// surplus '*' as empty. Thus, it continues to perform a scan from right to left, but treating '*' as close. 
// Similarly, if anytime close is fewer than open, return false. 
// Otherwise, return true, because it confirms either they are equal or there are indeed more '*'s. Thre
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0, len = s.size();
        for ( int i = 0; i < len; i++ ) {
            if ( s[i] == '(' || s[i] == '*' )
                open++;
            else 
                open--;
            if ( open < 0 )
                return false;
        }
        
        if ( open == 0 ) 
            return true;
        
        for ( int i = len - 1; i >= 0; i-- ) {
            if ( s[i] == ')' || s[i] == '*' ) 
                close++;
            else 
                close--;
            if ( close < 0 ) 
                return false;
        }
        
        return true;
    }
};

// Recursion method
// For the '*' case, we consider it being any of the three cases. And if any case is true, the whole 
// string is vald. 
// Note: this solution doesn't pass the online judgement. Memeory Limit Exceeded. 

class Solution {
public:
    bool checkValidString(string s) {
        return checkValidStringHelper(s,0,0);
    }
    
    bool checkValidStringHelper( string s, int start, int opencnt ) {
        if ( opencnt < 0 ) 
            return false;
        for ( int i = start; i < s.size(); i++ ) {
            if ( s[i] == '(' )
                opencnt++;
            else if ( s[i] == ')' ) {
                if ( opencnt <= 0 ) 
                    return false;
                opencnt--;
            }
            else {
                return checkValidStringHelper(s,i+1,opencnt) || checkValidStringHelper(s,i+1,opencnt+1) || checkValidStringHelper(s,i+1,opencnt-1) ;
            }
        }
        return opencnt == 0;
    }
};

// Dynamical programming 

// maximum and minimum opens 
// This solution is pretty novel. 
// It just tracks the minimum and mixinum number of opens as we iterate through the string 
// O(n), O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int MinOpen = 0, MaxOpen = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            switch( s[i] ) {
                case '(':
                    MinOpen++;
                    MaxOpen++;
                    break;
                case ')':
                    if ( MinOpen > 0 )
                        MinOpen--;
                    MaxOpen--;
                    break;
                case '*': 
                    if ( MinOpen > 0 )
                        MinOpen--;
                    MaxOpen++;
                    break;
            }
            if ( MaxOpen < 0 )
                return false;
        }
        
        return MinOpen == 0;
    }
};

// Dynamicl Programming 
// Top-down approach 
class Solution {
public:
    bool checkValidString( string s) {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        return isValid(dp,s,0,len-1);
    }
    
    bool isValid(vector<vector<int>> &dp, string str, int s, int e ) {
        if ( s > e ) 
            return true;
        if (dp[s][e] >= 0 )
            return dp[s][e];
        if ( s == e ) 
            return dp[s][e] = str[s] == '*';
        if ( (str[s] == '(' || str[s] == '*')
             && (str[e] == ')' || str[e] == '*')
             && isValid(dp,str,s+1,e-1))
            return dp[s][e] = 1;
        
        for  ( int mid = s; mid < e; mid++ ) 
            if ( isValid(dp,str,s,mid) && isValid(dp,str,mid+1,e))
                return dp[s][e] = 1;
        
        
        return dp[s][e] = 0;
    }

// Dynamical programming 
// Bottom-up approach 
class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        if ( len == 0 )
            return true;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for ( int i = 0; i < len; i++ ) {
            if (s[i] == '*' )
                dp[i][i] = 1;
        }
        
        for ( int strlen = 2; strlen <= len; strlen++ ) {
            for ( int start = 0; start <= len - strlen; start++ ) {
                int end = start + strlen - 1;
                if ( (s[start] == '(' || s[start] == '*')
                    && (s[end] == ')' || s[end] == '*' ))
                    if ( strlen == 2 || dp[start+1][end-1] ) {
                        dp[start][end] = 1;
                        continue;
                    }
            
                for ( int mid = start; mid < end; mid++ ) {
                    if ( dp[start][mid] && dp[mid+1][end] ) {
                       dp[start][end] = 1;
                      break;
                    }
                }
            }
        }
        return dp[0][len-1];
    }
};
};