// Problem Description
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

// For each element, we examine the cur_max and cur_min if can lead to 
// update the final_max if it needs to 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if ( nums.size() == 0 )
            return -1;
        int cur_max = nums[0];
        int cur_min = nums[0];
        int final_max = nums[0];
        for ( int i = 1; i < nums.size(); i++ )
        {
            int temp = cur_max; 
            cur_max = max(max(cur_max*nums[i],cur_min*nums[i]),nums[i]);
            cur_min = min(min(temp*nums[i],cur_min*nums[i]),nums[i]);
            if ( cur_max > final_max )
                final_max = cur_max;
        }
        
        return final_max;
    }
};

// we can simplifty the update of max,min depending on the sign of the current element
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if ( nums.size() == 0 )
            return -1;
        int cur_max = nums[0];
        int cur_min = nums[0];
        int final_max = nums[0];
        for ( int i = 1; i < nums.size(); i++ )
        {
            if ( nums[i] > 0 )
            {
                cur_max = max(cur_max*nums[i],nums[i]);
                cur_min = min( cur_min * nums[i], nums[i]);
            }
            else 
            {
                int t = cur_max;
                cur_max = max( cur_min * nums[i], nums[i] );
                cur_min = min( t * nums[i], nums[i] );
            }
            final_max = max( final_max, cur_max );
        }
        
        return final_max;
    }
};