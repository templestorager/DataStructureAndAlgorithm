// Problem Description
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

// This method just sequentially searches the pivot element. 
// Note that if we coulnd not find a pivot, i.e., there is no rotation, then we return the first element
// O(n), O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(); 
        if ( n <= 1 )
            return n;
        for ( int i = 0; i < n-1; i++ )
            if ( nums[i] > nums[i+1] )
                return nums[i+1];
        return nums[0];
    }
};

// Using binary search 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while ( l < r )     // Note using "<" here, since we are compare nums[m] with nums[m+1]
        {
            int m = l + (r-l)/2;
            if ( nums[m] > nums[m+1] )
                return nums[m+1];
            else if ( nums[m] > nums[l] )
            {
                l = m;
            } else {
                r = m;
            }
        }
        
        return nums[0];
    }
};

// More concise solution. Note in this solution we cann't compare mid with low.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};

// Divide and conquer
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinHelper(nums,0,nums.size()-1);
    }
    
    int findMinHelper( vector<int> &nums, int l, int r )
    {
        int mid = l + (r-l) / 2;
        if ( nums[l] <= nums[r] )
            return nums[l];
        return min(findMinHelper(nums,l,mid),findMinHelper(nums,mid+1,r));
    }
};