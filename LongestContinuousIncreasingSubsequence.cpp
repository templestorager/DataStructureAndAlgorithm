// Problem Description 
/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 0, cur_len;
        for ( int i = 0; i < nums.size(); i++ )
        {
            if ( i == 0 )
                cur_len = 1;
            else 
            {
                if ( nums[i] > nums[i-1] ) 
                    cur_len++;
                else 
                {
                    maxlen = max(maxlen,cur_len);
                    cur_len = 1;
                }
            }
        }
        
        maxlen = max(maxlen,cur_len);
        return maxlen;
    }
};

// Can write in a more concise manner 
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 0, candidate_idx = 0;
        for ( int i = 0; i < nums.size(); i++ )
        {
            if ( i > 0 && nums[i-1] >= nums[i] )
                candidate_idx = i;
            maxlen = max(maxlen,i - candidate_idx + 1 );
        }
        
        return maxlen;
    }
};