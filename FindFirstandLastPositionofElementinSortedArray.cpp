// Problem Description
/*
 Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

// Idea: use binary search to find the target and if it exists look left and right side to check 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = INT_MAX, first_pos, last_pos;
        int l = 0, r = nums.size();
        while ( l < r )
        {
            int mid = (l+r)/2;
            if ( nums[mid] == target ) 
            {
                pos = mid;
                break;
            }
            else if ( nums[mid] > target )
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        if ( pos == INT_MAX )
        {
            return {-1,-1};
        }
        first_pos = last_pos = pos;
        while( first_pos > 0 && nums[first_pos-1] == target )
            first_pos--;
        while(last_pos < nums.size()-1 && nums[last_pos+1] == target )
            last_pos++;
        return {first_pos,last_pos};
    }
};


// Idea: use binary search in the helper function which returns the position if target were to be 
// inserted into the sort array. If target exists in the array, then for left insert, it returns the position pointing to the first position 
// for right insert, the returned position points to the position after the last appreach of the target
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos,last_pos;
        first_pos = FindInsertValPosition(nums,target,true);
        if ( first_pos == nums.size() || nums[first_pos] != target )
        {
            return {-1,-1};
        }
        last_pos = FindInsertValPosition(nums,target,false);
        return {first_pos,last_pos-1};
    }
    
    int FindInsertValPosition( vector<int>& nums, int target, bool left )
    {
        int l = 0, r = nums.size();
        while ( l < r )
        {
            int mid = (l+r)/2;
            if ( nums[mid] > target || (left && nums[mid] == target) ) 
            {
                r = mid;
            }
            else 
            {
                l = mid + 1;
            }
        }
        
        return r;
    }
};