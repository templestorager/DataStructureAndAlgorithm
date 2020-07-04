// Problem Description
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

// This solution just sorts the string using a customized sorting comparator 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ch_m;
        for ( auto c : s )
            ch_m[c]++;
        sort( s.begin(), s.end(), [&](char a, char b){
            return ch_m[a] > ch_m[b]  || (ch_m[a] == ch_m[b] && a > b);
        });
        return s;
    }
};

// Could also leverage the sorting in a priority queue containing a pair
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        string res ="";
        unordered_map<char,int> m;
        for ( auto c : s )
            m[c]++;
        for ( auto e: m )
            pq.push({e.second,e.first});
        while ( !pq.empty() )
        {
            auto top = pq.top();
            pq.pop();
            res.append(top.first, top.second);  // append first parameter is number of char, second is the char
        }
        return res;
    }
};

// This function constructs the possible string including on the same char and the same length of string 
// Then cancatenate them.
class Solution {
public:
    string frequencySort(string s) {
        string res;
        vector<string> v(s.size()+1);
        unordered_map<char,int> m;
        for ( auto c : s )
            m[c]++;
        for ( auto &a : m )
            v[a.second].append(a.second,a.first);
        for ( int i = v.size() - 1; i >= 0; i-- )
            if ( !v[i].empty() )
                res.append(v[i]);
        return res;
    }
};