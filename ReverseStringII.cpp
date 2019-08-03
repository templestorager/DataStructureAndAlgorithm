// Problem Description 
/*
 * Given a string and an integer k, you need to reverse the first k characters for every 2k 
 * characters counting from the start of the string. If there are less than k characters left, 
 * reverse all of them. If there are less than 2k but greater than or equal to k characters, 
 * then reverse the first k characters and left the other as original.
    Example:
    Input: s = "abcdefg", k = 2
    Output: "bacdfeg"
    Restrictions:
    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]
 * 
 */

// Process blocks of 2K length 
class Solution {
public:
    string reverseStr(string s, int k) {
        int i,len = s.size();
        string res;

        int seg_2k = len / (2*k);
        for ( i = 0; i < seg_2k; i++ ) {
            string temp = s.substr(i*2*k,2*k);
            reverse(temp.begin(),temp.begin()+k);
            res.append(temp);
        }
        
        string remstr = s.substr(i*2*k);
        if ( remstr.size() < k ) {
            reverse(remstr.begin(),remstr.end());
            res.append(remstr);
        }
        else {
            reverse(remstr.begin(),remstr.begin()+k);
            res.append(remstr);
        }
        
        return res;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for ( int i = 0; i < s.size(); i += 2 * k ) {
            int start = i, end = i + k - 1 < s.size()-1 ? i + k - 1 : s.size() - 1;
            while ( start < end ) 
                swap(s[start++],s[end--]);
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for ( int i = 0; i < s.size(); i += 2 * k ) {
            reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
        }
        return s;
    }
};