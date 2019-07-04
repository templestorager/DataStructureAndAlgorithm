// Problem Description 
/* 
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the 
 * array. Formally the function should:
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
 * 
 */

// This solution uses dynamic programming approach. 
// The array records the number of elements which are less than the current index element. 
// O(n^2), O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> LessThanMe(nums.size(),1);
        for ( int i = 0; i < nums.size(); i++ ) { 
            for ( int j = 0; j < i; ++j ) {
                if ( nums[j] < nums[i] ) {
                    LessThanMe[i] = max(LessThanMe[i],LessThanMe[j] + 1 );
                    if ( LessThanMe[i] >= 3 )
                        return true;
                }
            }
        }
        return false;
    }
};

// This solution is similar to DP idea. 
// For each element, it remembers the left minimum and right maximum value. 
// O(n), O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(); 
        if ( n < 3 ) 
            return false;
        vector<int> left_min(n, nums[0]), right_max(n,nums[n-1]);
        for ( int i = 1; i < n; i++ )
            left_min[i] = min( left_min[i-1], nums[i] );
        
        for ( int i = n - 2; i >= 0; i-- ) 
            right_max[i] = max( right_max[i+1], nums[i]);
        for ( int i = 0; i < n; i++  ) {
            if ( nums[i] > left_min[i] && nums[i] < right_max[i] ) 
                return true;
        }
        
        return false;
    }
};

// This solution is tricky. 
// It proceeds using two variables to remember the two limits. 
// The key point is to appreciat the "if...else if...else ", which implictly accounts for in whether 
// the two limits have been updated or not. 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int lower = INT_MAX, mid = INT_MAX; 
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] <= lower ) 
                lower = nums[i];
            else if ( nums[i] <= mid ) 
                mid = nums[i];
            else 
                return true;               
        }
        return false;
    }
};