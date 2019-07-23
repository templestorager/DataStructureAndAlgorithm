// Problem Description 
/*
 * Given a non-empty array of integers, every element appears twice except for one. Find that 
 * single one.

    Note:

    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:

    Input: [2,2,1]
    Output: 1
    Example 2:

    Input: [4,1,2,1,2]
    Output: 4
 * 
 */

// This solution uses the XOR operation 
// O(n), O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            res ^= nums[i];
        }
        return res;
    }
};

// This solution uses the hast set 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for ( auto num:nums ) {
            if ( s.count(num) ) 
                s.erase(num);
            else 
                s.insert(num);
        }
        
        return *s.begin();
    }
};

// Leverage the math: 
// the result is: 2 * (unique numbser) - sum(given set)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        s.clear();
        int sum1 = 0, sum2 = 0; 
        for ( int i = 0; i < nums.size(); i++ ) {
            s.insert(nums[i]);
        }

        for ( set<int>::iterator it = s.begin(); it != s.end(); it++ ) {
            sum1 += *it;
        }
        
        sum1 *= 2; 
        
        for ( int i = 0; i < nums.size(); i++ ) {
            sum2 += nums[i];
        }
        return sum1 - sum2;     
    }
};