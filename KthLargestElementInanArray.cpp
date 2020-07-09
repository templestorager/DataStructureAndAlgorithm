// Problem Description 
/* 
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in 
 * the sorted order, not the kth distinct element.

    Example 1:

    Input: [3,2,1,5,6,4] and k = 2
    Output: 5
    Example 2:

    Input: [3,2,3,1,2,4,5,5,6] and k = 4
    Output: 4
    Note: 
    You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// Naive solution: sorting and returning the k-thing counting from the end 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

// Uses the priority_queue. By default the priority queue has the largetest on the top 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        for ( int i = 0; i < k-1; i++ ) {
            q.pop();
        }
        return q.top();
    }
};

// O(n*lgk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for ( int i = 0; i < nums.size(); i++ ) { 
            pq.push(nums[i]);
            if ( pq.size() > k ) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// This solution leverages the fact that a pass of quick sort finds the position of an element 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while ( true ) {
            int pos = partition(nums,left,right);
            if ( pos == k-1 )
                return nums[pos];
            else if ( pos > k - 1 )
                right = pos - 1;
            else 
                left = pos + 1;
        }
    }
    
    int partition(vector<int> &nums, int left, int right ) {
        int pivot = nums[left], l = left + 1, r = right;
        while ( l <= r ) {
            if ( nums[l] < pivot && nums[r] > pivot ) {
                swap(nums[l++],nums[r--]);
            }
            if ( nums[l] >= pivot ) 
                l++;
            if ( nums[r] <= pivot )
                r--;
        }
        swap(nums[left],nums[r]);
        return r;
};