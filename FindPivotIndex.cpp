// Problem description 
/*
* Given an array of integers nums, write a method that returns the "pivot" index of this array. We define
the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum 
of the numbers to the right of the index. If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
*
 */

// this solution is straightforward, i.e., checks the left and right sums of each index 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum, rightsum;
        for ( int i = 0; i < nums.size(); i++ ) {
            leftsum = 0, rightsum = 0;
            for( int left = 0; left < i; left++ )
                leftsum += nums[left];
            for( int right = i+1; right < nums.size(); right++ )
                rightsum += nums[right];
            if ( leftsum == rightsum )
                return i; 
        }
        return -1;
    }
};

// We can calculate the total sum first
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int TotalSum = accumulate( nums.begin(), nums.end(), 0 );
        int sumL = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            if( 2 * sumL == TotalSum - nums[i] )
                return i;
            sumL += nums[i];
        }
        return -1;
    }
};