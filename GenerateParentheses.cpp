// Problem Description
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

// This is the recursion solution, when tries to add the number of left and right parentheses 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        helper( res, n, n, str);
        return res;
    }
    void helper( vector<string> &res, int left, int right, string cur )
    {
        if ( left > right ) 
            return ;
        if ( left == 0 && right == 0 )
        {
            res.push_back(cur);
            return;
        }
        if ( left > 0 )
            helper( res, left-1, right, cur+'(');
        if ( right > 0 )
            helper( res, left, right-1, cur+')');
    }
};