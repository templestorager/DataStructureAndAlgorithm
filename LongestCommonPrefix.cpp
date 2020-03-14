// Problem Description
/*
 Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minsz = INT_MAX,j; 
        if ( strs.size() == 0 )
            return "";
        for ( int i = 0; i < strs.size(); i++ ) 
            if ( strs[i].size() < minsz )
                minsz = strs[i].size();
        for ( j = 0; j < minsz; j++ )
        {
            for ( int i = 1; i < strs.size(); i++ )
            {
                if ( strs[i][j] != strs[0][j])
                {
                    return strs[0].substr(0,j);
                }
            }
        }
        if ( j == 0 )
            return "";
        return strs[0].substr(0,minsz);
    }
};


// Vertical searching and compare 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() )
            return "";
        for ( int i = 0; i < strs[0].size(); i++ )
        {
            for ( int j = 1; j < strs.size(); j++ ) 
            {
                if ( i >= strs[j].size() || strs[0][i] != strs[j][i] )
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        
        return strs[0];
    }
};

// if we sort the strings, then the longest common prefix string would be the common prefix between 
// the first and the last
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() )
            return "";
        if ( strs.size() == 0 )
            return strs[0];
        sort( strs.begin(), strs.end() );
        int i = 0, len = std::min(strs[0].size(),strs.back().size());

        while ( i < len && strs[0][i] == strs.back()[i] ) 
            i++;
        
        return strs[0].substr(0,i);
    }
};

// Divid and conquer 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.size() == 0 )
            return "";
        return LongestCommonPrefix( strs,0,strs.size() - 1 );
    }
    
    string LongestCommonPrefix( vector<string>& strs, int l, int r )
    {
        if ( l == r )
        {
            return strs[l];
        }
        else
        {
            int mid = (l+r)/2;
            string lcpleft = LongestCommonPrefix( strs, l, mid );
            string lcpright = LongestCommonPrefix( strs, mid+1, r);
            return CommonPrefix( lcpleft, lcpright );
        }
    }
    
    string CommonPrefix( string left, string right ) 
    {
        int i = 0, len = std::min(left.size(),right.size());
        while ( i < len && left[i] == right[i] ) 
            i++;
        return left.substr(0,i);
    }
};