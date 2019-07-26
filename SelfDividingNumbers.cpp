// Problem Description 
/*
 * A self-dividing number is a number that is divisible by every digit it contains.

    For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

    Also, a self-dividing number is not allowed to contain the digit zero.

    Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

    Example 1:
    Input: 
    left = 1, right = 22
    Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
    Note:

    The boundaries of each input argument are 1 <= left <= right <= 10000.
 */

// check every and each number in the given range to see whether it is a self-dividing number or not

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for ( int i = left; i <= right; i++ )  {
            if ( i == 0 ) 
                continue;
            if  ( i < 0 ) 
                i = -i;
            int temp = i;
            while ( temp > 0 ) {
                int rem = temp % 10; 
                if( rem == 0 || i % rem ) 
                    break;
                temp /= 10;
            }
            
            if ( temp == 0 ) 
                res.push_back(i);
        }
        
        return res;
    }
};

// This solution transforms the a given number to string first. 
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int j;
        for ( int i = left; i <= right; i++ )  {
            string val = to_string(i);
            for ( j = 0; j < val.size(); j++ ) {
                if ( val[j] == '0' || i % (val[j]-'0') ) 
                    break;
            }      
            if ( j == val.size() )
                res.push_back(i);
        }
        
        return res;
    }
};