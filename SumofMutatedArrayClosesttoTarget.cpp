// Problem Description
/*
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

 

Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
Example 2:

Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5

*/

// This solution uses (implicitly) the binary search algorithm to find the threshold. 
// First, we need to identify the range of the possible result, which is [0,max(arr)], because all numbers are larger
// than 1 ( as indicated by the description) and not larger than the max ( as further increasing this value won't change the sum at all ). 
// Knowing this, we can use binary search to find the value which has the minimum difference 
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left = 0, right = *max_element(arr.begin(),arr.end());
        int diff = INT_MAX, res;
        while ( left <= right )
        {
            int mid = left + (right-left)/2;
            int sum = SumTrim( arr, mid );
            int cur_diff = abs(sum-target);
            if ( cur_diff < diff ) 
            {
                res = mid;
                diff = cur_diff;
            }
            else if ( cur_diff == diff ) 
            {
                res = min(res,mid);
            }
            if ( sum == target )
            {
                return mid;
            }
            else if ( sum > target ) 
            {
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        
        return res;
    }
    
private: 
    int SumTrim( vector<int> &arr, int t )
    {
        int sum = 0; 
        for ( auto val : arr )
        {
            if ( val > t )
            {
                sum += t;
            }
            else 
            {
                sum += val;
            }
        }
        return sum;
    }
};

// Gradually increase the min value and then the nearest integer to the average value should be the result 
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size(), i = 0;
        while ( i < n && target > arr[i]*(n-i) )
        {
            target -= arr[i++];
        }
        
        return i == n ? arr[n-1] : int(round(((float)target - 0.1)/(n-i)));
        #if 0
        if ( i == n )
            return arr[n-1];
        int res = target / (n-i);
        
        if ( target - res*(n-i) > (res+1) * (n-i) - target )
            res ++;
        return res;
        #endif 
    }
};