// Problem Description 
/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.

 * Note:

 * The solution set must not contain duplicate triplets.
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 *
 */

// The solution sorts the nums first, and then fix one element and find the remaining sums

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if ( nums.empty() || nums.back() < 0 || nums.front() > 0 ) 
            return {};
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] > 0 )
                break;
            if ( i > 0 && nums[i] == nums[i-1] )
                continue;
            int gap = 0 - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while ( j < k ) {
                if ( nums[j] + nums[k] == gap ) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while ( j < k && nums[j] == nums[j+1] ) j++;
                    while ( j < k && nums[k] == nums[k-1] ) k--;
                    j++;
                    k--;
                } else if ( nums[j] + nums[k] < gap) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};
