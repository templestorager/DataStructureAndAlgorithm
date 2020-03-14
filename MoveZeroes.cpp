// Problem Description 
/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

// Idea: if the current number is zero, then we find the first non-zero after it 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j;
        while ( i < n-1 )
        {
            if ( nums[i] == 0 )
            {
                for ( j = i+1; j < n; j++ )
                {
                    if ( nums[j] != 0 )
                    {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                if ( j == n - 1 )
                    return;
            }
            i++;
        }
    }
};

// two pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        for ( i = 0, j = 0; j < n; j++ ) 
        {
            if ( nums[j] != 0 )
            {
                nums[i++] = nums[j];
            }
        }
        for ( ; i < n; i++ )
            nums[i] = 0;
    }
};