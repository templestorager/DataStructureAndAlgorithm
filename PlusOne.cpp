// Problem Description
/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(),i;
        if ( n == 0 )
            return {1};
        int carry = 1;
        for ( i = n-1; i >= 0; i--)
        {
            int sum = digits[i]+carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if ( i == -1 && carry )
            digits.insert(digits.begin(),{1});
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if ( n == 0 )
            return {1};
        for ( int i = n-1; i >= 0; i-- )
        {
            if ( digits[i] == 9 )
            {
                digits[i] = 0;
            }
            else 
            {
                digits[i]++;
                return digits;
            }
        }
        digits = vector<int>(n,0);
        digits.insert(digits.begin(),1);
        return digits;
    }
};