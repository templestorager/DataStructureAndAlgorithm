// Problem Description 
/*
    Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

    A majority element is an element that appears more than N/2 times in an array of length N.
    Example 1:

    Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
    Output: true
    Explanation: 
    The value 5 appears 5 times and the length of the array is 9.
    Thus, 5 is a majority element because 5 > 9/2 is true.
    Example 2:

    Input: nums = [10,100,101,101], target = 101
    Output: false
    Explanation: 
    The value 101 appears 2 times and the length of the array is 4.
    Thus, 101 is not a majority element because 2 > 4/2 is false.
 
 */

// count the appearances of each number 
// O(n), O(1)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        for ( int i = 0; i < n; i++ ) {
            m[nums[i]]++;
        }
        
        return m[target] > n/2;
    }
};

// Leveraging the given non-decreasing order feature
// Note: the problem should emphasize that a majority number exists!!
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return nums[(nums.size()-1)/2 ] == target;
    }
};