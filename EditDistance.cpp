// Problem Description 
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

// This is a recursion with memo solution. 
// dp[i][j] means the minDistance between word1[0...i-1] and word1[0...j-1]. 
// The value of dp[i][j] depends on word1[i-1] being equal to word2[j-1] or not 
// If equal, then it's value is dp[i-1][j-1].
// Otherwise, we need to make a change to make them the same (i.e., one change) 
// plus the min of the state before make the change, i.e., three cases: 
// dp[i-1][j-1]: replace or flip the word1[i] and word2[j]
// dp[i-1][j]:   delete word1[i] from word1
// dp[i][j-1]:   insert word2[j] to word2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        dp_ = vector<vector<int>>(l1+1,vector<int>(l2+1,-1));
        return minDistance(word1,word2,l1,l2);
    }
private:
    vector<vector<int> > dp_;
    int minDistance( const string &word1, const string &word2, int l1, int l2 )
    {
        if ( l1 == 0 )
            return l2;
        if ( l2 == 0 )
            return l1;
        if ( dp_[l1][l2] >= 0 )
            return dp_[l1][l2];
        int ans; 
        if ( word1[l1-1] == word2[l2-1] )
            ans = minDistance( word1, word2, l1-1, l2-1);
        else 
        {
            ans = min(minDistance(word1,word2,l1-1,l2-1),min(minDistance(word1,word2,l1-1,l2),minDistance(word1,word2,l1,l2-1))) + 1;
        }
        
        return dp_[l1][l2] = ans;
    }
};

// we can translate the above recursion method to bottom-up dynamic programming 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int dp[l1+1][l2+1];
        for ( int i = 0; i <= l1; i++ )
            dp[i][0] = i;
        for ( int i = 0; i <= l2; i++ )
            dp[0][i] = i;
        for ( int i = 1; i <= l1; i++ )
            for ( int j = 1; j <= l2; j++ )
            {
                int replace = word1[i-1] == word2[j-1] ? 0 : 1;
                dp[i][j] = min(dp[i-1][j-1]+replace,min(dp[i-1][j],dp[i][j-1]) + 1 );
            }
        return dp[l1][l2];
    }
};