// Problem Description 
/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *  [3],
 *  [1],
 *  [2],
 *  [1,2,3],
 *  [1,3],
 *  [2,3],
 *  [1,2],
 *  []
 * ]
 */

// This solution add a num from the set one by one. 
// it adds a num to all subsets existing so far 
// O(n^2),O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(),nums.end());
        for ( int i = 0; i < nums.size(); i++ ) {
            int sz = res.size();
            for ( int j = 0; j < sz; j++ )  {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};

// This solutions uses dfs to construct the subsets. 
// For each element, we have only two choices: either select or not select 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempres;
        sort(nums.begin(),nums.end());
        dfs(res,tempres,0,nums);
        return res;
    }
    
    void dfs( vector<vector<int>> &res, vector<int> &tempres, int curidx, const vector<int> nums) 
    {
        if ( curidx == nums.size() ) {
            res.push_back(tempres);
            return ;
        }
        tempres.push_back(nums[curidx]);
        dfs(res,tempres,curidx+1,nums);
        tempres.pop_back();
        dfs(res,tempres,curidx+1,nums);
        
    }
};

// The total number of subsets is 2^n, which each number between [0,2^n) can be 
// perceived as the bit values each of which represents the selection of a corresponding element

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.clear();
        vector<int> tempres;
        int maxval = 1 << nums.size();
        
        for ( int i = 0; i < maxval; i++ )  {
            tempres.clear();
            int idx = 0; 
            for ( int val = i; val > 0; val >>= 1 ) {
                if ( val & 1 ) {
                    tempres.push_back(nums[idx]);
                }
                idx++;
            }
            res.push_back(tempres);
        }
        return res;
    }
};