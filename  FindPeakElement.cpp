// Problem Description
/*
 A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
*/

// Idea: since we are asked to find any local peak, we just need to find the an elment whose following 
// element is smaller than it
// O(n), O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for( int i = 0; i < nums.size() - 1; i++ ) 
        {
            if ( nums[i+1] < nums[i] )
                return i;
        }
        return nums.size() - 1;
    }
};

// Idea: similarly inverse search 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for ( int i = nums.size() - 1; i > 0; i-- )
        {
            if ( nums[i-1] < nums[i] )
                return i;
        }
        return 0;
    }
};

// This method uses binary search to find any of the local peak, which satisfies the condition, i.e., 
// the following element is smaller than itself
// O(lgn), O(lgn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums,0,nums.size()-1);
    }
private: int search( vector<int>& nums, int low, int high )
    {
        if ( low == high )
            return low;
        int mid = (low+high)/2;
        if ( nums[mid] > nums[mid+1] )
            return search(nums,low,mid);
        return search(nums,mid+1,high);
    }
};

// This is just an iterative vesion of the above recursive code 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while( l < r )
        {
            int mid = (l+r)/2;
            if ( nums[mid] > nums[mid+1] )
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};