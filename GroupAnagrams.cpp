// Problem Description
/*
 * Given an array of strings, group anagrams together.
 */

// this solution uses the heuristic that the sorted string of an anagram is the same 
// it then builds a map associating with the sorted string as the key and the anagram.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string> > AnagramMap; 
        AnagramMap.clear();
        for ( int i = 0; i < strs.size(); i++ ) {
            string t(strs[i]);
            sort(t.begin(),t.end());
            AnagramMap[t].push_back(strs[i]);
        }
        
        for ( map<string, vector<string> >::iterator it = AnagramMap.begin(); it != AnagramMap.end(); it++ )
            res.push_back(it->second);
        return res;
    }
};

// uses a different calculation method to obtain the map key 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string> > AnagramMap; 
        AnagramMap.clear();
        for ( string str: strs ) {
            vector<int> CharNum(26,0);
            string key;
            for ( char ch : str ) 
                CharNum[ch-'a']++;
            for ( int cnt : CharNum )
                key += string(1,cnt+'a') + to_string(cnt);
            AnagramMap[key].push_back(str);
        }
        
        for ( auto it : AnagramMap )
            res.push_back(it.second);
        return res;
    }
};