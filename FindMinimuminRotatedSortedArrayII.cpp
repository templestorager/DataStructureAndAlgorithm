// Problem Description
/*
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
*/

// This problem has only one difference in that the examined mid value might be equal to left or right end. 
// We just need to shorten the interval by 1 in this case. 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while ( l < r )
        {
            int m = l + (r-l) / 2;
            if ( nums[m] > nums[m+1] )
                return nums[m+1];
            if ( nums[m] < nums[r] )
            {
                r = m;
            }
            else if ( nums[m] > nums[r] )
            {
                l = m+1;
            }
            else {
                r--;
            }
        }
        return nums[0];
    } 
};

// We can also use divide and conquer. 
// Note the check conditions due to possible existence of duplicate values 
// In the previous questiong having no duplicate, condition nums[l] <= nums[r] implies either 
// [l,r] are in a sorted sequence or l == r, which doesn't hold any more if there are duplicates 
// for example, in the case of nums[l] == nums[mid] == nums[r]
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinHelper(nums,0,nums.size()-1);
    } 
    
    int findMinHelper(vector<int> &nums, int l, int r)
    {
        if ( l == r || nums[l] < nums[r] )
            return nums[l];
        int m = l + (r-l)/2;
        return min(findMinHelper(nums,l,m),findMinHelper(nums,m+1,r));
    }
};