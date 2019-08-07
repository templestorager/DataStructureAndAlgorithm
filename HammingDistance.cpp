// Problem Description
/*
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.

    Note:
    0 ≤ x, y < 231.

    Example:

    Input: x = 1, y = 4

    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
        ↑   ↑

    The above arrows point to positions where the corresponding bits are different.
 * 
 * 
 */

// Calculate the number of 1s in the XORed result 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int hammingdistance = 0;
        int xorres = x^y;
        while ( xorres ) {
            if ( xorres & 1 ) 
                hammingdistance++;
            xorres >>= 1;
        }
        
        return hammingdistance;
    }
};

// The similar idea as the above, but leverage the observation that num & (num-1) stripes off the 
// LSB 1. So it only iterates the number of 1s times.  
class Solution {
public:
    int hammingDistance(int x, int y) {
        int hammingdistance = 0;
        int xorres = x^y;
        while ( xorres ) {
            hammingdistance++;
            xorres &= xorres - 1;
        }
        
        return hammingdistance;
    }
};

// Recursive solution
// (x^y) % 2 is the value of the LSB bit. 
class Solution {
public:
    int hammingDistance(int x, int y) {
        if ( (x ^ y) == 0 )
            return 0;
        return (x^y) % 2 + hammingDistance(x/2,y/2);
    }
};