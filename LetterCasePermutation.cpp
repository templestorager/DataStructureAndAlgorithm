// Problem Description 
/*
 Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/
// This method starts from an empty result set and then for each letter: 
// if it is a number, then we just add the number to each of the current members in the set 
// if it is a char, then we double the size of the current result and then add an UPPER case of the 
// char to half of the set and add a lower case of the char to the other half (newly generated) result set
// after we have processed all the chars, we will obtain all the results 
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{""};
        for ( auto c : S )
        {
            if ( isdigit(c) )
            {
                for ( auto &str : res )
                    str.push_back(c);
            }
            else 
            {
                int len = res.size();
                for ( int i = 0; i < len; i++ )
                {
                    res.push_back(res[i]);
                    res.back().push_back(toupper(c));
                    res[i].push_back(tolower(c));
                }
            }
        } 
        return res;
    }
};

// This recursion uses dfs which is a common approach. 
// Notice there is a difference that it doesn't pop the last element like in many other problems.
// The reason is it has to take the path (i.e., the current char has to be included)
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(res,0,S);
        return res;
    }
    
    void helper(vector<string> &res, int idx, string &s)
    {
        if ( idx == s.size() )
        {
            res.push_back(s);
            return;
        }
        helper(res,idx+1,s);
        if ( isalpha(s[idx]) )
        {
            s[idx] ^= 32;
            helper(res,idx+1,s);
        }
    }
};