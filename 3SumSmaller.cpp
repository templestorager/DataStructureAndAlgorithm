// Problem Description 
/*
    Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

    Example:

    Input: nums = [-2,0,1,3], and target = 2
    Output: 2 
    Explanation: Because there are two triplets which sums are less than 2:
                [-2,0,1]
                [-2,0,3]
    Follow up: Could you solve it in O(n2) runtime?
 * 
 */

// brute force, check each triplet 
// O(n^3), O(1)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        if ( nums.size() < 3 )
            return res;
        for ( int i = 0; i < nums.size() - 2; i++ ) {
            int l = i+1, r = nums.size() - 1, sum = target - nums[i];
            for ( int j = l; j <= r; j++ ) {
                for ( int k = j + 1; k <= r; k++ ) {
                    if ( nums[j] + nums[k] < sum )
                        res++;
                }
            }
        }
        
        return res;
    }
};

// This solution optimizes over the above solution by first sorting and then using two pointers 
// method whose complexity is only O(n), making the overall complexity being O(n^2). 
// O(n^2), O(1)

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        if ( nums.size() < 3 )
            return 0;
        for ( int i = 0; i < nums.size() - 2; i++ ) {
            sum += twoSumSmaller(nums,i+1,target-nums[i]);
        }
        return sum;
    }
private:
    int twoSumSmaller(vector<int> nums, int StartIndx, int target ) {
        int sum = 0;
        int l = StartIndx, r = nums.size() - 1;
        while ( l < r ) {
            if ( nums[l] + nums[r] < target ) {
                sum += r - l;
                l++;
            }
            else 
            {
                r--;
            }
        }
        return sum;
    }
};