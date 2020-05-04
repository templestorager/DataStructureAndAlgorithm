// Problem Description 
/* 
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

// Brute force solution 
// This equated nume should be in the range [min,max]. We check each possible case and find the smallest number of 
// moves.
// O(n*diff), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if ( nums.size() == 0 ) 
            return 0;
        int len = nums.size(); 
        int res = INT_MAX;
        int low = nums[0], high = nums[0];
        for ( int i = 1; i < len; i++ )
        {
            if ( nums[i] < low )
                low = nums[i];
            if ( nums[i] > high )
                high = nums[i];
        }
        
        for ( int equal_val = low; equal_val <= high; equal_val++ )
        {
            long sum = 0;
            for ( auto num : nums )
                sum += abs(num-equal_val);
            if ( sum < res )
                res = sum;
        }
        return res;   
    }
};

// Actually we can just consider the existing elements in the array rather then the whole range as the final equal value. 
// There is some trivial proof to show that this will result in fewer moves than choosing a value not existing in the array.
// O(n^2), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        if ( n == 0 )
            return 0;
        for ( auto val : nums )
        {
            long sum = 0;
            for ( auto num : nums )
                sum += abs( num - val );
            if ( sum < res )
                res = sum;
        }
        
        return res;
    }
};

// The following method is similar to the above solution, but use sorting to facilitate the calculation 
// Specifically, for an element nums[i] to be considered as the final value, the amount of increment moves before it is equal to 
// nums[i]*i - sum(0...i-1), and the amount of decrement moves after it (including itself which is 0) is remaining sum (total_sum - sum) 
// minus nums[i] * ( len - i ). 
// O(nlogn), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        long res = INT_MAX, sum = 0, total_sum = 0;
        int len = nums.size();
        for ( auto num : nums )
            total_sum += num;
        for ( int i = 0; i < nums.size(); i++ )
        {
            long moves = ((long)nums[i]*i - sum) + (total_sum-sum) - (long)nums[i]*(len-i);
            if ( moves < res )
                res = moves;
            sum += nums[i];
        }
        
        return res;
    }
};