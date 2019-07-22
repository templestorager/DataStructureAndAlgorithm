// Problem Description 
/*
 *
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Example 1:
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * 
 * Example 3:
 * Input: 14
 * Output: false 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * Note:
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−231,  231 − 1]. 
 * 
 */

// This solution divides the num by all 2,3,5 and if at any time if it's not a multipe of those factors 
// then it must be a non-ugly number. 
// If it is an ugly number, then at last it must be equal to one. 
// O(lgn), O(1)
class Solution {
public:
    bool isUgly(int num) {
        vector<int> primefactors{2,3,5};
        int i; 
        while ( num >= 2 ) {
            for ( i = 0; i < primefactors.size(); i++ ) {
                if ( num % primefactors[i] == 0 ) {
                    num /= primefactors[i]; 
                    break;
                }
            }
            if ( i == primefactors.size() )
                return false;
        }
        return num == 1;
    }
};

// This  solution is essentially the same as the above solution, but more concise. 
class Solution {
public:
    bool isUgly(int num) {
        vector<int> primefactors{2,3,5};
        if ( num == 0 ) 
            return false;
        for ( int i = 0; i < primefactors.size(); i++ ) {
            while ( num % primefactors[i] == 0 ) {
                num /= primefactors[i];
            }
        }
        return num == 1;
    }
};