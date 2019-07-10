// Problem Description 
/*
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * Example:
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
 * Note:
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity
 * 
 * 
 */

// This solution uses recursion to obtain the length of increasing subsequences
// For each element, it could be two cases: valid and should be included in the subsequence 
// or invalid and should be skipped
// However, this solution leads to Time Limit Exceeded.
// O(2^n) O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLISHelper(nums,INT_MIN, 0 );
    }
    
    int lengthOfLISHelper( vector<int> &nums, int prev, int curpos ) {
        if ( curpos == nums.size() ) 
            return 0;
        int cur_valid = 0;
        if ( nums[curpos] > prev ) {
            cur_valid = 1 + lengthOfLISHelper(nums,nums[curpos],curpos+1);
        }
        int cur_invalid = 0; 
        cur_invalid = lengthOfLISHelper(nums,prev,curpos+1);
        return max(cur_valid, cur_invalid);
        
    }
};

// this solution improves over the previous solution by avoiding calling the recursive funciton 
// with the same parameters using a memorization array[length+1][length]
// memo[i][j] represents the length of the LIS possible using nums[i] as the previous 
// element considered to be included/not included in the LIS, with nums[j] as the current 
// element considered to be included/not included in the LIS.
// O(n^2) O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(),vector<int> (nums.size(),-1));
        return lengthOfLISHelper(nums,-1, 0,memo );
    }
    
    int lengthOfLISHelper( vector<int> &nums, int prev, int curpos, vector<vector<int>> &memo ) {
        if ( curpos == nums.size())
            return 0;
        if ( memo[prev+1][curpos] >= 0 )
            return memo[prev+1][curpos];
        int taken = 0; 
        if ( prev < 0 || nums[curpos] > nums[prev] ) 
            taken = 1 + lengthOfLISHelper(nums,curpos,curpos + 1, memo );
        int nottaken = lengthOfLISHelper(nums,prev,curpos+1,memo);
        memo[prev+1][curpos] = max(taken,nottaken);
        return memo[prev+1][curpos];  
    }
};

// This solution uses dynamic programming. 
// lisdp[idx] is the value of max LIS including nums[idx]
// O(n^2) O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};