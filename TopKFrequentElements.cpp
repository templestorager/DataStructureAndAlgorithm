// Problem Description
/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

// We use a priority queue ( max heap default ) to keep the maximum k elements 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for ( auto &num : nums )
            m[num]++;
        for ( auto it : m )
            pq.push({it.second,it.first});
        for ( int i = 0; i < k; i++ )
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

// After obtaining the mapping counts, we can use bucket counting to get the k most frequent elements seraching 
// starting from the end of the bucket 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        vector<vector<int>> bucket(nums.size()+1);
        
        for ( auto &num : nums )
            m[num]++;
        for ( auto it : m )
        {
            bucket[it.second].push_back(it.first);
        }
        int idx = nums.size();
        for ( int i = 0; i < k; )
        {
            int cnt = 0;
            if ( !bucket[idx].empty() )
            {
                cnt = bucket[idx].size();
                for ( auto a : bucket[idx] )
                    res.push_back(a);
            }
            idx--;
            i += cnt;
        }
        return res;
    }
};