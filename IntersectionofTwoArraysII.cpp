// Problem Description 
/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/

// We also need to take the occurrence into account 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        vector<int> res;
        for ( auto n1 : nums1 )
            m1[n1]++;
        
        for ( auto n2 : nums2 )
            if ( --m1[n2] >= 0 )
                res.push_back(n2);
        
        return res;             
    }
};

// We can also sort the arrays to avoid using extra memory 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res; 
        int i = 0, j = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while ( i < nums1.size() && j < nums2.size() )
        {
            if ( nums1[i] == nums2[j] )
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if ( nums1[i] < nums2[j] ) 
            {
                i++;
            }
            else 
            {
                j++;
            }
        }
        
        return res;
    }
};