// Problem Description 
/*
 * Given a non-empty array of integers, every element appears three times except for one, 
 * which appears exactly once. Find that single one.

    Note:

    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:

    Input: [2,2,3,2]
    Output: 3
    Example 2:

    Input: [0,1,0,1,0,1,99]
    Output: 99

 */

// This solution sums the number of 1s at each position
// The remainders of 3 at each position is then the only distinct value at the corresponding position
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; 
        for ( int i = 0; i < 32; i++ ) {
            int sum = 0;
            for ( int j = 0; j < nums.size(); j++ ) {
                if ( nums[j] & 1 << i ) 
                    sum++;
            }
            
            res |= (sum % 3) << i;
        }
        
        return res;
    }
};

// one, two, three represent the number of 1s on each position are 1, 2 and 3 respectively. 
// The following is the transition table:
// # of 1     one        two       three    
//   1         1          0          0
//   2         0          1          0
//   3         0          0          1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            two |= (one & nums[i] );        // update two, it's based on one 
            one ^= nums[i];                 // update one 
            three = ~(one & two);           // update three 
            one &= three;                   //  clear one
            two &= three;                   // clear two 
        }
        
        return one;
    }
};

// if a number appears twice, then it's xor would remove the 1s it had contributed to the result
// meaning we can use only once and twice to represent all the cases 
// So: 
// For once: an incoming number would offset any number which has alreay appeared once 
// For twice: an incoming number renders out which have already appreached twice 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0; 
        for ( auto num : nums )
        {
            once  = ~twice & ( once ^ num );    // not in the twice but in the once minus the number itself if it was in the once (i.e., it now becomes twice or three times, in both cases it should be gone)
            twice = ~once & ( twice ^ num );    // similarly, not in the once but in the twice minus the number itself it was in the twice(i.e., it becomes three times )
        }
        return once;
    }
};