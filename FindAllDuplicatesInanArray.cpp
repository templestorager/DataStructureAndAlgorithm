// Problem Description 
/*
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and 
 * others appear once.
 *  Find all the elements that appear twice in this array.

    Could you do it without extra space and in O(n) runtime?

    Example:
    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]
 * 
 */

// This method leverages the following two facts: 
// 1. all values are in [0,n-1]
// 2. and idx values are also in [0,n-1]
// It then marks the existence of a value by negating the element, which means 
// when negating nums[nums[idx]-1], we are declaring the existence of value (idx+1).
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for ( int i = 0; i < nums.size(); i++ ) {
            int idx = abs(nums[i]) - 1;
            if ( nums[idx] < 0 )
                res.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        
        return res;
    }
};

// This solution is similar in spirit to the above solution in that it also checks the existence 
// of value, but by adding n to each of the number. 
// If a value has appeared twice, then 2xn will be added to value. 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            nums[(nums[i]-1)%n] += n;
        }
        
        for ( int i = 0; i < n; i++ ) {
            if ( nums[i] > 2*n ) 
                res.push_back(i+1);
        }
        
        return res;
    }
};

// This solutin actually first sorts the array taking advantage of characteristics of 
// the ranges of values being in the range [1,n]
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res; 
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] != nums[nums[i]-1] )  {
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }
        
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] != i+1 )
                res.push_back(nums[i]);
        }
        
        return res;
    }
};