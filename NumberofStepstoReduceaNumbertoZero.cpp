// Problem Description
/* 
Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12
*/

// check each bit 
// Alternative, we can count the number of 1s and zeros  in the number
// for each 1, we increment two steps, and for each 0, we increment 1 step
// then finally decrement by as the last 1 (the most significant bit) only needs once step (i.e., minus 1)
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while ( num )
        {
            if ( num & 1 ) 
                num &= (num - 1 );  // flip over the trailing 1
            else 
                num >>= 1;
            step++;
        }
        
        return step;
    }
};

