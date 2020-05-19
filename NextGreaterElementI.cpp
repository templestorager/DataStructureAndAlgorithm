// Problem Description
/*
 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

// This straightfoward method checks the existence of the elements in nums2 using linear searching
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i, j;
        for ( i = 0; i < nums1.size(); i++ )
        {
            bool exist = false;
            for ( j = 0; j < nums2.size(); j++ )
            {
                if ( exist && nums2[j] > nums1[i] )
                {
                    res.push_back(nums2[j]);
                    break;
                }
                if ( nums2[j] == nums1[i] )
                {
                    exist = true;
                }
            }
            if ( j == nums2.size() )
                res.push_back(-1);
        }
        
        return res;
    }
};

// This method optimizes the searching in nums2 a little by storing maping its elements to indexes 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int,int> m;
        int j;
        for ( int i = 0; i < nums2.size(); i++ )
        {
            m[nums2[i]] = i;
        }
        
        for ( int i = 0; i < nums1.size(); i++ )
        {
            res[i] = -1;
            if ( m.count(nums1[i]) == 0 )
                continue;
            
            int pos = m[nums1[i]];
            for ( j = pos + 1; j < nums2.size(); j++ )
            {
                if ( nums2[j] > nums1[i] )
                {
                    res[i] = nums2[j];
                    break;
                }
            }
            
            if ( j == nums2.size() )
                res[i] = -1;
        }
        
        return res;
    }
};


// This method uses the monotone stack to construct the next greater of nums2. 
// Then to obtain the result for nums1, we just consult the map 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int,int> m; // map an element to it's next greater index in nums2
        stack<int> nextgreater;
        for ( int i = nums2.size() - 1; i >= 0; i-- )
        {
            while ( !nextgreater.empty() && nums2[nextgreater.top()] < nums2[i] )
                nextgreater.pop();
            if ( nextgreater.empty() )
                m[nums2[i]] = -1;
            else 
                m[nums2[i]] = nums2[nextgreater.top()];
            nextgreater.push(i);
        }
        
        for ( int i = 0; i < nums1.size(); i++ )
            res[i] = m[nums1[i]];
        return res;
    }
};