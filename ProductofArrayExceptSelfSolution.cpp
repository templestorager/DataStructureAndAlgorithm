// Problem Description
/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

// This solution uses two auxiliary arrays. 
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> L_P(n), R_P(n);
    vector<int> res;
    for ( int i = 0; i < n; i++ )
    {
        if ( i == 0 )
            L_P[i] = 1;
        else 
            L_P[i] = L_P[i-1] * nums[i-1];
    }
    
    for ( int i = n - 1; i >= 0; i-- )
    {
        if ( i == n - 1 )
            R_P[i] = 1;
        else 
            R_P[i] = R_P[i+1] * nums[i+1];
    }
    
    for ( int i = 0; i < n; i++ )
    {
        res[i] = L_P[i] * R_P[i];
    }
    
    return res;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for ( int i = 0; i < n; i++ )
        {
            if ( i == 0 )
                res[i] = 1;
            else 
                res[i] = res[i-1] * nums[i-1];
        }
        
        int R = 1;
        
        for ( int i = n-1; i >= 0; i-- )
        {
            res[i] *= R;
            R *= nums[i];
        }
        
        return res;
    }
};