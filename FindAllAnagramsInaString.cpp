// Problem Description 
/*
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will 
 * not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input: 
 * s: "cbaebabacd" p: "abc"
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * Example 2:
 * Input:
 * s: "abab" p: "ab"
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab". 
 */

// This solution is brute force apporach. 
// It checks every possible start index in the s and check whether it is an anagram from there. 
// O(m*n*lgn), O(1)
// Note: it leads to Time Limit Exceeded. 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if ( s.size() < p.size() ) 
            return res;
        int slen = s.size(), plen = p.size();

        for ( int i = 0; i < slen; i++ ) {
            if ( slen - i < plen )
                break;
            if  (IsAnagrams(s.substr(i,plen),p))
                res.push_back(i);
        }
        return res;
    }
    
    int IsAnagrams(string str1, string str2) { 
        if ( str1.size() != str2.size() )
            return false;
        sort(str1.begin(),str1.end()); 
        sort(str2.begin(),str2.end());
        return str1 == str2;
    }
};

// This solution improves over the above solution by optimizing the checking of anagram 
// O(m*n), O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int pmap[26] = {0};
        
        int slen = s.size(), plen = p.size();
        for ( int i = 0; i < plen; i++ ) 
            pmap[p[i]-'a']++;
        
        for ( int i = 0; i <= slen - plen; i++ ) {
            if  (IsAnagrams(s.substr(i,plen),pmap))
                res.push_back(i);
        }
        return res;
    }
    
    bool IsAnagrams(string str1, const int pmap[26] ) 
    { 
        int m[26];
        memcpy(m,pmap,sizeof(m));
        for( int i = 0; i < str1.size();i++) 
            if ( --m[str1[i]-'a'] < 0 )
                return false;
        return true;
    }
};

// This solution uses a dynamic char map for s as chars are moved in and out
// O(m), O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int slen = s.size(), plen = p.size();
        vector<int> smap(26,0), pmap(26,0);
        if ( slen == 0 || slen < plen ) 
            return res;
        for ( int i = 0; i < plen; i++ ) {
            smap[s[i]-'a']++;
            pmap[p[i]-'a']++;
        }
        if ( smap == pmap )
            res.push_back(0);
        for ( int i = plen; i < slen; i++ ) {
            smap[s[i]-'a']++;
            smap[s[i-plen]-'a']--;
            if ( smap == pmap ) 
                res.push_back(i-plen+1);
        }
        return res;
    }
};

// This solution uses only one map table. 
// As we move in one char (right) and leave one char (left), we decrease and 
// increase the map table, respectively. 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        int left = 0, right = 0;
        vector<int> res, m(26,0);
        int cnt_to_match = plen;
        if ( slen == 0 ) 
            return {};
        for ( int i = 0; i < plen; i++ ) 
            m[p[i]-'a']++;
        while ( right < slen ) {
            if ( m[s[right++]-'a']-- >= 1 ) cnt_to_match--;
            if ( cnt_to_match == 0 )
                res.push_back(left);
            if ( right - left == plen && m[s[left++]-'a']++ >= 0 ) {
                cnt_to_match++;       
            }
        }
        return res;
    }
};
