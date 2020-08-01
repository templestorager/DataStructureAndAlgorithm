// Problem Description 
/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

 

Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: A = [1,2,4], K = 3
Output: 6
Explanation: 
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
 

Note:

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/

// For each element at position idx, we can calculate how many numbers are missing using the following equation:
// nums[idx] - nums[0] - idx,
// Then our goal is to find the and position idx which satisfies the following condition: 
// missingcnt(idx-1) < k <= missingcnt(idx). 
// Once we have found this position, we can simply return:
// nums[idx-1] + k - missingcnt(idx-1);
// O(n), O(1)
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        if ( k > missingcnt(nums,n-1) )
        {
            return nums[n-1] + k - missingcnt(nums,n-1);
        }
        // find missingcnt(nums,idx-1) < k <= missingcnt(nums,idx)
        int idx = 1; 
        while ( missingcnt(nums,idx) < k ) 
            idx++;
        
        return nums[idx-1]+k-missingcnt(nums,idx-1);
    }
private:
    // return how many numbers are missing until idx 
    int missingcnt( const vector<int> &nums, int idx )
    {
        return nums[idx] - nums[0] - idx;
    }
};

// We can use binary search to find the idx satisfying the condition. 
// Note we just need to handle the case when the missing number is beyond the last element 
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = n - 1, idx; 
        if ( nums[n-1] - nums[0] + 1 - n < k )
            return nums[n-1] + k - missingcnt(nums,n-1);
        while ( l < r )
        {
            idx = l + (r-l) / 2;
            if ( missingcnt(nums,idx-1) > k  ) 
            {
                r = idx; 
            }
            else if ( missingcnt(nums,idx) < k )
            {
                l = idx+1;
            }
            else if ( missingcnt(nums,idx-1) < k && missingcnt(nums,idx) >= k )
            {
                break;
            }
        }
        return nums[idx-1] + k - missingcnt(nums, idx-1);
    }
private: 
    int missingcnt ( const vector<int> &nums, int idx )
    {
        return nums[idx] - nums[0] - idx;
    }
};

// Another version of using binary searching 
// Find the left-most position, which satisfies the condition
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = n - 1, idx; 
        if ( missingcnt(nums,n-1) < k )
            return nums[n-1] + k - missingcnt(nums,n-1);
        while ( l != r )
        {
            idx = l + (r-l) / 2;

            if ( missingcnt(nums,idx) < k )
                l = idx+1;
            else 
                r = idx;
        }
        return nums[l-1] + k - missingcnt(nums, l-1);
    }
private: 
    int missingcnt ( const vector<int> &nums, int idx )
    {
        return nums[idx] - nums[0] - idx;
    }
};

// We can maintain an accumulative missing count 
// O(n), O(1)
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int missingcnt = 0, n = nums.size();
        for ( int i = 1; i < nums.size(); i++ )
        {
            int cur_gap = nums[i] - nums[i-1] - 1;
            if ( missingcnt + cur_gap >= k )
            {
                return nums[i-1] + k - missingcnt;
            }
            else 
            {
                missingcnt += cur_gap;
            }
        }
        
        return nums[n-1] + k - missingcnt;
    }
};