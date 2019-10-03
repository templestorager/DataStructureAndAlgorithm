// Problem Description 
/*
    Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

    Example:

    Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
    Output: [3,3,5,5,6,7] 
    Explanation: 

    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
 * 
 */

// Brute force solution
// O(N*k), O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if ( n == 0 ) 
            return vector<int> {};
        vector<int> res;
        for ( int i = 0; i <= n-k; i++ ) {
            int windowmax = nums[i];
            for ( int j = i + 1; j < i + k; j++ ) {
                windowmax = max( windowmax, nums[j] );
            }
            res.push_back(windowmax);
        }
        return res;
    }
};

// This solution uses the ordered multiset to keep the elments in the window sorted. 
// At any time the number of elments in the set is less (beginning phase) or equal than k
// O(nlgk), O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> setwindow;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( i >= k )
                setwindow.erase(setwindow.find(nums[i-k]));
            setwindow.insert(nums[i]);
            if ( i >= k-1 )
                res.push_back(*setwindow.rbegin());
        }
        
        return res;
    }
};


// This solution uses the priority queue to facilitate getting the maximum value so far
// The difference from the above solution is that it may contain more than k elements in the 
// priority_queue.
// O(nlgn), O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for ( int i = 0; i < nums.size(); i++ ) {
            while( !pq.empty() && pq.top().second <= i-k )
                pq.pop();
            pq.push({nums[i],i});
            if ( i >= k - 1 )
                res.push_back(pq.top().first);
        }
        
        return res;
    }
};


// This is a cool solution usign deque struture, which stores the index of maximum values only. 
// O(n), O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( !dq.empty() && dq.front() == i - k ) 
                dq.pop_front();
            while ( !dq.empty() && nums[dq.back()] < nums[i] ) 
                dq.pop_back();
            dq.push_back(i);
            if ( i >= k - 1 )
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};