// Problem description: 
/* 
A string S of lowercase letters is given. We want to partition this string into as many parts as possible 
so that each letter appears in at most one part, and return a list of integers representing the size of 
these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only. 
*/

// Idea: the key point is that once a char appears in a part, all the chars until its last position 
// should be included in the same part. 
// Method: 
// We remember the last postions of each every char in the string. 
// While walking through the string, we update the max position upon examining the next char. 
// the termination condition is when we hit the so far max position, which is a cut point. 

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int sz = S.size(), s = 0, e = 0;
        unordered_map<char, int> map;
        for ( int i = 0; i < sz; i++ )
            map[S[i]] = i;      // record the maximum idx for each char 
        for ( int i = 0; i < sz; i++ ) {
            e = max(e,map[S[i]]);
            if ( i == e ) {
                res.push_back( i - s + 1 );
                s = i + 1;
            }
        }
        return res;   
    }
};