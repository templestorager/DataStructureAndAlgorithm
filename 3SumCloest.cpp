// Problem Description
/*
    Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    Example:

    Given array nums = [-1, 2, 1, -4], and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// Idea: similar to the 3Sum problem, but we need to dynamically track the updated optimal val
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort( nums.begin(), nums.end() );
        int diff = abs(target-closest);
        for ( int i = 0; i < nums.size() - 2; i++ )
        {
            int j = i + 1, k = nums.size() - 1;
            if ( 3 * nums[i] > target )
            {
                closest = min(closest, nums[i]+nums[i+1]+nums[i+2]);
                break;
            }
            while ( j < k )
            {
                int sum = nums[i] + nums[j] + nums[k];
                int newdiff = abs( target - sum );
                if ( newdiff < diff ) 
                {
                    diff = newdiff;
                    closest = sum;
                }
                
                if ( sum < target ) 
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return closest;
    }
};