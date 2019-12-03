// Problem Description 
/*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    Example:

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    Follow up:

    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*
*/

// The key idea is the when we check a number, the accumulative could be more than itself or less than 
// itself. Therefore, we know the local maximum is max of the accumulative sum so far or the number itself 
// i.e., we started a new subarray 
// O(n), O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for ( auto num : nums ) {
            curSum = max(curSum + num, num );
            res = max(res, curSum);
        }
        
        return res;
    }
};


// This solution uses divide and conquer method, i.e., calculate the left max, right max, and middle max containing the 
// middle element, and then return the max of the three
// O(NlogN), O(logN)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        return helper( nums, 0,nums.size()-1);
    }
    
private: 
    int helper(vector<int> &nums, int left, int right ) {
        if ( left >= right ) 
            return nums[left];
        int mid = left + ( right - left ) / 2;
        int lmax = helper(nums,left, mid-1);
        int rmax = helper(nums,mid+1,right);
        int mmax = nums[mid], tmp = mmax;
        for ( int i = mid-1; i >= left; i-- ) {
            tmp += nums[i];
            mmax = max(mmax,tmp);
        }
        
        tmp = mmax;
        for ( int i = mid+1; i <= right; i++ ) {
            tmp += nums[i];
            mmax = max(mmax,tmp);
        }
        
        return max( lmax, max(rmax,mmax) );
    }
};

// This solution uses dynamic programming method leveraging the array as the DP array.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.empty() ) 
            return 0;
        int max_sum = nums[0];
        for ( int i = 1; i < nums.size(); i++ ) {
            if ( nums[i-1] > 0 )
                nums[i] += nums[i-1];
            max_sum = max(nums[i],max_sum);
        }
        
        return max_sum;
    }
};