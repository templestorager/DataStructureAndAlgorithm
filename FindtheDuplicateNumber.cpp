// Problem Description 
/*
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate 
 * number, find the duplicate one.

    Example 1:

    Input: [1,3,4,2,2]
    Output: 2
    Example 2:

    Input: [3,1,3,4,2]
    Output: 3
    Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.
 * 
 */

// This solution sorts the numbers first and then find the duplicate one 
// O(nlgn), O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for ( int i = 1; i < nums.size(); i++ ) {
            if ( nums[i] == nums[i-1] ) 
                return nums[i];
        }
        
        return -1;
    }
};

// This solution uses set to recorde the existing nums
// O(n), O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for( int i = 0; i < nums.size(); i++ ) {
            if ( seen.count(nums[i]) ) 
                return nums[i];
            seen.insert(nums[i]);
        }
        return -1;
    }
};

// This approach uses cycle detection 
// O(n), O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while ( tortoise != hare );
        
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while ( ptr1 != ptr2 ) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        
        return ptr1;
    }
};

// This solution uses binary search. It recursively compares the numbers of values less than mid value 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size();
        while ( low < high ) {
            int mid = low + (high-low) / 2, cnt = 0;
            for ( int num : nums ) {
                if ( num <= mid ) 
                    cnt++;
            }
            
            if ( cnt <= mid ) 
                low = mid + 1;
            else 
                high = mid;
        }
        
        return high;
    }
};