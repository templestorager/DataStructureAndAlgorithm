// Problem Description 
/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/

// use set help remove duplicates 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1; 
        unordered_set<int> res;
        for ( auto n1 : nums1 ) 
            s1.insert(n1);
        for ( auto n2 : nums2 )
        {
            if ( s1.count(n2) )
            {
                res.insert(n2);
            }
        }
        
        return vector<int>(res.begin(),res.end());
    }
};