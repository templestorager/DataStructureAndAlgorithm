// Problem Description
/*

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

// Naive solution: check every possible substring 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m_substr;
        int slen = s.length();
        if ( slen < 10 )
            return res;
        for ( int i = 0; i <= slen-10; i++ )
        {
            string str = s.substr(i,10);
            m_substr[str]++;
            if ( m_substr[str] == 2 )
            {
                res.push_back(str);
            }
        }
        
        return res;
    }
};


// Using sliding window and check the current string in the window whether it has appreared before or not
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m_substr;
        int slen = s.length();
        if ( slen < 10 )
            return res;
        string strwin = s.substr(0,10);
        m_substr[strwin]++;
        for ( int i = 10; i < slen; i++ )
        {
            strwin.push_back(s[i]);
            strwin.erase(strwin.begin());
            m_substr[strwin]++;
            if ( m_substr[strwin] == 2 )
            {
                res.push_back(strwin);
            }
        }
        
        return res;
    }
};