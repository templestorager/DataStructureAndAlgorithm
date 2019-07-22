// Problem Description 
/* 
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * Example:
 * Input: [1,2,2]
 * 
 * Output:
 *  [
 *      [2],
 *      [1],
 *      [1,2,2],
 *      [2,2],
 *      [1,2],
 *      []
 *  ]
 * 
 */

// These following two solutions are based on the first two solutions of the Subset problem
// Given the existence of duplicate nums, if the next num is a duplicate, then we only need to 
// add it to the previous subsets which include all the preceding duplicates. Adding it to further before 
// subsets leads to duplicat subsets. 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
        int firstsame = curidx; 
        while( firstsame >= 0 && nums[firstsame] == nums[curidx] ) firstsame--;
        firstsame++; 
        int sameNum = curidx - firstsame;
        if ( sameNum == 0  ||
            (tempres.size() >= sameNum && tempres[tempres.size()-sameNum] == nums[curidx] ) )
            {
                tempres.push_back(nums[curidx]);
                dfs(res,tempres,curidx+1,nums);
                tempres.pop_back();
            }
        dfs(res,tempres,curidx+1,nums);
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(),nums.end());
        int last = nums[0], subsetsNum = 1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] != last ) {
                last = nums[i];
                subsetsNum = res.size();
            }
            int sz = res.size();
            for ( int j = sz-1; j >= sz-subsetsNum; j-- )  {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};