// Problem Description
/*
 * 
    Given a collection of distinct integers, return all possible permutations.
    Example:
    Input: [1,2,3]
    Output:
    [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
    ]
 * 
 * 
 */


// Backtracking method 
// between O(nxn!) and O(n!). O(n!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> seen;
        vector<vector<int>> res;
        vector<int> onepermutation;
        helper(res,nums,onepermutation,seen);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int>& nums, vector<int>& onepermutation, unordered_set<int> &seen) {
        if ( onepermutation.size() == nums.size() ) { 
            res.push_back(onepermutation);
            return;
        }
        
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( !seen.count(nums[i]) ) {
                seen.insert(nums[i]);
                onepermutation.push_back(nums[i]);
                helper(res,nums,onepermutation,seen);
                onepermutation.pop_back();
                seen.erase(nums[i]);
            }
        }
    }
};

// This recursive method tries to swap each pair of numbers
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteDFS(res,0,nums);
        return res;
    }
    
    void permuteDFS(vector<vector<int>> &res, int start, vector<int> &nums) {
        if ( start == nums.size() ) {
            res.push_back(nums);
        }
        
        for ( int i = start; i < nums.size(); i++ ) {
            swap(nums[start],nums[i]);
            permuteDFS(res,start+1,nums);
            swap(nums[start],nums[i]);
        }
    }
};

// This solution leverages the fact that adding a number to generate a permute would have n+1 possibility 
// which n is the current number of permution. 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if ( nums.empty() ) 
            return vector<vector<int>>(1,vector<int>());
        vector<vector<int>> res;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> tailpermute = permute(nums);
        for ( auto a : tailpermute ) {
            for ( int i = 0; i <= a.size(); i++ ) {
                a.insert(a.begin()+i,first);
                res.push_back(a);
                a.erase(a.begin()+i);
            }
        }
        
        return res;
    }
};


// This solution is an eqiuvalent iteration implement of the above recursive method. 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res{{}};
        for ( int a : nums ) {
            for ( int k = res.size(); k > 0; k-- ) {
                vector<int> t = res.front();
                res.erase(res.begin());
                for ( int i = 0; i <= t.size(); i++ ) {
                    vector<int> tmp = t;
                    tmp.insert(tmp.begin()+i,a);
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
};

// This solution is kind of tricky, leveraging the STL next_permutation function which generates the next 
// lexicographically greater permutation. Therefore, we have to sort it first to obtain the first permuation. 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        do {
            res.push_back(nums);
        } while( next_permutation(nums.begin(),nums.end())); 
        return res;
    }
};