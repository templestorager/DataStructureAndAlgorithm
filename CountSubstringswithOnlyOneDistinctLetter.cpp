// Problem Description
/*
 * 
    Given a string S, return the number of substrings that have only one distinct letter.

    Example 1:

    Input: S = "aaaba"
    Output: 8
    Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
    "aaa" occurs 1 time.
    "aa" occurs 2 times.
    "a" occurs 4 times.
    "b" occurs 1 time.
    So the answer is 1 + 2 + 4 + 1 = 8.
    Example 2:

    Input: S = "aaaaaaaaaa"
    Output: 55
    

    Constraints:

    1 <= S.length <= 1000
    S[i] consists of only lowercase English letters.
 * 
 */

// brute force 
// it checks every char as the starting point of a string 
// O(n^2) O(1)
class Solution {
public:
    int countLetters(string S) {
        int ans = 0; 
        int i = 0, j;
        while ( i < S.size() ) 
        {
            j = i;
            while ( S[i] == S[j] && j < S.size() ) {
                ans++;
                j++;
            }
            i++;
        }
        return ans;
    }
};

// This following has a slight improvement over the above solution
// It uses math to calculate the number of substrings of a substring consisting of unique chars
// O(n), O(1)
class Solution {
public:
    int countLetters(string S) {
        int ans = 0; 
        int i = 0, j;
        while ( i < S.size() ) 
        {
            j = i;
            while ( S[i] == S[j] && j < S.size() ) {
                j++;
            }
            int uniquechars = j - i;
            ans += ( (uniquechars + 1 ) * uniquechars  / 2 );
            i = j;
        }
        return ans;
    }
};

// This solution is essentially the same as the above, but incrementally increases the counter whenever 
// a same char is encountered
// O(n), O(1)
class Solution {
public:
    int countLetters(string S) {
        int ans = S.size();
        for ( int i = 0, j = 1; j < S.size(); j++ ) {
            if ( S[i] == S[j] ) {
                ans += j - i;
            }
            else 
            {
                i = j;
            }
        }
        
        return ans;
    }
};

// The following is a dynamic programming solution 
// We initialize the memory array to 1, because eash individual char can be a qualified substring in itself 
// O(n), O(n)
class Solution {
public:
    int countLetters(string S) {
        int n = S.size();
        vector<int> res(n,1);
        for ( int i = 1; i < n; i ++ ){
            if ( S[i] == S[i-1] ) {
                res[i] = res[i-1] + 1;
            } 
        }
        return accumulate(res.begin(),res.end(),0);
    }
};