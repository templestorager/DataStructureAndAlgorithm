// Problem Description 
/*
    Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    Example:

    Given array nums = [-1, 2, 1, -4], and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */ 

// Based on the 3Sum problem, check each triplet and record the minimum value
// O(n^2), O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff = INT_MAX;
        int closestsum = -1; 
        if ( nums.size() < 3 ) 
            return closestsum;
        sort(nums.begin(),nums.end());
        for ( int i = 0; i < nums.size() - 2; i++ ) {
            int j = i + 1, k = nums.size() - 1;
            while ( j < k ) {
                int sum = nums[i] + nums[j] + nums[k];
                int newdiff = abs(target - sum);
                if ( newdiff < mindiff ) {
                    mindiff = newdiff;
                    closestsum = sum;
                }
                if ( sum < target ) 
                    j++;
                else 
                    k--;
            }
        }
        
        return closestsum;
    }
};