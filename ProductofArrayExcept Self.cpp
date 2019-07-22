// Problem Description 
/*
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is 
 * equal to the product of all the elements of nums except nums[i].
 * 
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// We record the left and right product of an index element. 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_product(n,1), right_product(n,1), res(n,0);
        for ( int i = 1; i < n; i++ ) 
            left_product[i] = left_product[i-1] * nums[i-1];
        for ( int i = n-2; i >= 0; i--)
            right_product[i] = right_product[i+1] * nums[i+1];
        for ( int i = 0; i < n; i++ ) 
            res[i] = left_product[i] * right_product[i];
        return res;
    }
};

// This solution uses the same answer space instead of the using additional space. 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int right = 1;
        for ( int i = 1; i < n; i++ ) 
            res[i] = res[i-1] * nums[i-1];
        for ( int i = n-1; i >=0; i--) {      
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};