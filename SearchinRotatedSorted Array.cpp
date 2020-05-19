// Problem Description
/*
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

// This method is baseed on the conventional binary search algorithm with additional checks. 
// By comparing with the nums[mid] with either the left end(nums[l]) or right end(nums[r]), we can 
// determine which part is completed sorted, i.e., the part not containing the pivot point

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while ( l <= r )
        {
            int mid = l + (r-l) / 2;
            if ( nums[mid] == target )
                return mid;
            else if ( nums[mid] >= nums[l] )
            {
                if ( nums[l] <= target && nums[mid] > target )
                {
                    r = mid - 1;
                }
                else 
                {
                    l = mid + 1;
                }
            }
            else 
            {
                if( nums[r] >= target && nums[mid] < target )
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }
        
        return -1;
    }
};