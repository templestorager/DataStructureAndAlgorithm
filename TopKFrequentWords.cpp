// Problem Description 
/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

// This solution simply uses a customized sorting comparator, which sorts the words based on their frequencies
// But beware to remove the duplicates before sorting 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        set<string> s;
        vector<string> res;
        for ( auto &w : words )
        {
            m[w]++;
            s.insert(w);
        }
        words = vector<string>(s.begin(),s.end());
        sort(words.begin(),words.end(),[&](const string &a, const string &b) {
            if ( m[a] < m[b] )
            {
                return false;
            }
            else if ( m[a] == m[b] ){
                if ( a < b )
                    return true;
                else 
                    return false;
            }
            else {
                return true;
            }
        });
        for ( int i = 0; i < k; i++ )
            res.push_back(words[i]);
        return res;  
    }
};

// We can use priority queue to help sorting as well 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        vector<string> res;
        struct Cmp {
            bool operator() (const pair<int,string> &a, const pair<int,string> &b ) {
                if ( a.first < b.first )
                    return true;
                else if ( a.first == b.first )
                {
                    if ( a.second >= b.second )
                        return true;
                    else 
                        return false;
                }
                else {
                    return false;
                }
            }
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>, Cmp > pq;
        for ( auto &w : words )
            m[w]++;
        for ( auto it : m )
        {
            pq.push({it.second,it.first});
        }
        
        for ( int i = 0; i < k; i++ )
        {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        
        return res;
    }
};