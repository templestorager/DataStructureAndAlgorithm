// Problem Description
/*
 
    Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

    Example 1:
    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
    Example 2:
    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    Note: The length of the given binary array will not exceed 50,000.
*/

// For subarray related problems, it's always good to consider accumulative sum which should give us some insight into the solution 
// If we maintain a dynamic sum which is incremented by 1 for 1 and decremented by 1 for a 0, then whenever we encounter the same sum, 
// we know there are equal number of 0s and 1s in between. 
// We maintain a hashmap which maps the sum (or count) to the first index which leads to the sum 
// If we later on encounter the same sum, we update the max_len result
// O(n), O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count_m{{0,-1}};
        int max_len = 0, count = 0;
        for ( int i = 0; i < nums.size(); i++ ){
            count += nums[i] ? 1 : -1;
            if ( count_m.count(count) )
            {
                max_len = max(max_len,i-count_m[count]);
            } else {
                count_m[count] = i;
            }
        }
        
        return max_len;
    }
};