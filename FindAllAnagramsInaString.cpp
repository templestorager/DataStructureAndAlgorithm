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

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if ( s.size() < p.size() )
            return {};
        vector<int> res;
        int m[26] = {0};
        int plen = p.length();
        int slen = s.length();
        for ( int i = 0; i < plen; i++ )
            m[p[i]-'a']++;
        for ( int j = 0; j <= slen - plen; j++ )
            if ( IsAnagram(s.substr(j,plen),m) )
                res.push_back(j);
        
        return res;
    }
    
    bool IsAnagrams( string str, const int m[26] )
    {
        int count[26];
        memcpy( count, m, sizeof(m) );
        for ( int i = 0; i < str.size(); i++ )
        {
            if ( --count[str[i]-'a'] < 0 );
                return false;
        }
        
        return true;
    }
};

// Generally for this pattern search problem, we can use sliding window approach to scoping into the 
// the substrings in the s string and then compare it with the pattern. 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pcount[26] = {0};
        int scount[26] = {0};
        vector<int> res;
        int slen = s.length(), plen = p.length();
        for ( int i = 0; i < plen; i++ )
            pcount[p[i]-'a']++;
        for ( int i = 0; i < slen; i++ )
        {
            scount[s[i]-'a']++;
            // if we have moved in one more char on the right side, we need to move out the left-most char 
            if ( i >= plen )
            {
                scount[s[i-plen]-'a']--;
            }
            // if we have the exact number of the chars, it's time to make a comparision 
            if ( i >= plen - 1 && !memcmp(scount,pcount,sizeof(pcount)) )
            {
                res.push_back( i - plen + 1 );
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int i; 
        int plen = p.size(), slen = s.size();
        if ( plen > slen || slen == 0  )
            return {};
        int pcount[26] = {0}, scount_win[26] = {0}; 
        for ( i = 0; i < plen; i++ )
        {
            pcount[p[i]-'a']++;
            scount_win[s[i]-'a']++;
        }
        
        while ( i <= slen )
        {
            if ( memcmp(pcount,scount_win,sizeof(pcount)) == 0 )
                res.push_back(i-plen);
            scount_win[s[i-plen]-'a']--;
            if ( i < slen )
                scount_win[s[i]-'a']++;
            i++;
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, m(256,0);
        int slen = s.size(), plen = p.size(), left = 0, right = 0, rem_cnt = plen;
        if ( plen < slen || slen == 0 )
            return {};
        for ( char a : p )
            m[a]++;
        while ( right < slen )
        {
            if ( m[s[right++]]-- >= 1 )
                rem_cnt--;
            if ( rem_cnt == 0 )
                res.push_back(left);
            if ( right - left == plen && m[s[left++]]++ >= 0 )
                //if ( m[s[left++]]++ >= 0 )
                    rem_cnt++;
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size(), left = 0, right = 0, rem_cnt = plen;
        vector<int> res, m(256,0);
        if ( plen > slen || slen == 0 )
            return {};
        for ( auto c : p )
            m[c]++;
        while ( right < slen )
        {
            if ( m[s[right++]]-- > 0 )
                rem_cnt--;
            if ( rem_cnt == 0 )
                res.push_back(left);
            if ( right-left == plen && m[s[left++]]++ >= 0 )
                rem_cnt++;
        }
        
        return res;
    }
};