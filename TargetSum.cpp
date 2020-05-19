// Problem Description
/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

// This recursion method considers possibilities at each step 
// O(2^n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        helper( nums,S,0,count );
        return count;
    }
    
    void helper( vector<int> &nums, long S, int idx, int &count )
    {
        if ( idx == nums.size() ) {
            if ( S == 0 )
                ++count;
            return;
        }
        
        helper( nums, S+nums[idx],idx+1,count);
        helper( nums, S-nums[idx],idx+1,count);
    }
};

// We can add memoization to avoid redundant calculation 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,int> > memo(nums.size());
        return helper(nums,S,0,memo );
    }
    
    int helper( vector<int> &nums, long remsum, int idx, vector<unordered_map<int,int>> &memo )
    {
        if ( idx == nums.size() )
            return remsum == 0;
        if ( memo[idx].count(remsum) )
            return memo[idx][remsum];
        int plus_cnt = helper( nums, remsum+nums[idx],idx+1,memo);
        int minus_cnt = helper( nums, remsum-nums[idx], idx+1, memo);
        return memo[idx][remsum] = plus_cnt + minus_cnt;
    }
};

// This method uses a two dimension array to remember the cnt of each sum 
// dp[i][j] indicates how many the cases of sum ending at nums[i-1]. 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int> > dp(n+1);
        dp[0][0] = 1;   //there is only one case summing to zero when there is no element considered 
        for ( int i = 0; i < n; i ++ ){
            for ( auto &a : dp[i] )
            {
                int sum = a.first, cnt = a.second;
                dp[i+1][sum+nums[i]] += cnt;
                dp[i+1][sum-nums[i]] += cnt;
            }
        }
        
        return dp[n][S];
    }
};

// We can also use an n-sized dp, but be careful about the initialization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int> > dp(n);
        dp[0][nums[0]]  += 1;       // cover the case when nums[0] already exists, in this case 0
        dp[0][-nums[0]] += 1;       // ditto

        for ( int i = 1; i < n; i++ ){
            for ( auto &a : dp[i-1] )
            {
                int sum = a.first, cnt = a.second;
                dp[i][sum+nums[i]] += cnt;
                dp[i][sum-nums[i]] += cnt;
            }
        }
        
        return dp[n-1][S];
    }
};

// we can avoid using an array of maps, the dp map gets bigger and bigger as we move to 
// 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> dp;
        dp[0] = 1;
        for ( auto num : nums )
        {
            unordered_map<int,int> t;
            for ( auto a : dp )
            {
                int sum = a.first, cnt = a.second;
                t[sum+num] += cnt;
                t[sum-num] += cnt;
            }
            dp =t;
        }
        
        return dp[S];
    }
};