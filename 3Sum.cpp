// Problem Description
/*
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

// Idea: 
// Sorting, and fix one using two pointers 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if ( nums.empty() || nums.front() > 0 || nums.back() < 0 ) 
        {
            return {};
        }
        
        for ( int i = 0; i < (int)nums.size() - 2; i++ )    // got to typecast to int
        {
            if ( nums[i] > 0 )
                break;
            if ( i > 0 && nums[i] == nums[i-1] )
            {
                continue;
            }
            int target = 0 - nums[i], j = i+1, k = (int)nums.size() - 1;
            while ( j < k )
            {
                if ( nums[j] + nums[k] == target ) 
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while( j < k && nums[j] == nums[j+1] ) j++;
                    while( j < k && nums[k] == nums[k-1] ) k--;
                    j++;
                    k--;
                } 
                else if ( nums[j] + nums[k] < target ) 
                {
                    j++;
                }
                else 
                {
                    k--;
                }
            }
        }
        
        return res;
    }
};



