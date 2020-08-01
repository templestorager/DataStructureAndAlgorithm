// Problem Description
/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
*/

#if 0
// We can check whether the power of 2 numbers have the same set of digits as the given number
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        multiset<int> s; 
        CalculateDigitsSet( N, s );
        
        for ( int i = 0; i < 32; i++ )
        {
            multiset<int> tmp;
            CalculateDigitsSet( 1 << i, tmp );
            if ( tmp == s )
                return true;
        }
        
        return false;
    }
    
    void CalculateDigitsSet( int num, multiset<int> &s )
    {
        while ( num )
        {
            s.insert( num % 10 );
            num /= 10;
        }
    }
};

// The same idea, we could sort the string comprising of all the digits of the given number 
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = to_string(N);
        sort(str.begin(),str.end());
        for ( int i = 0; i < 32; i++ )
        {
            string tmp = to_string( 1 << i );
            sort( tmp.begin(), tmp.end() );
            if ( tmp == str )
                return true;
        }
        
        return false;
    }
};
#endif 


// We can also find out all the permutations and then check each of them to see if it is a power of 2.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> digits;
        vector<vector<int>> permutes;
        while ( N )
        {
            digits.push_back( N % 10 );
            N /= 10;
        }
        permutes = permute(digits);
        for ( auto p : permutes )
            if ( IsPower2(p) )
                return true;
        return false;
    }
    
    bool IsPower2( const vector<int> &digits )
    {
        int val = 0;
        if ( digits[0] == 0 )
            return false;
        for ( int i = 0; i < digits.size(); i++ )
        {
            val *= 10;
            val += digits[i];
        }
        
        return (val & val - 1) == 0;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for ( auto a : nums )
        {
            for ( int k = res.size(); k > 0; k-- )
            {
                vector<int> t = res.front();
                res.erase(res.begin());
                for ( int i = 0; i <= t.size(); i++ )
                {
                    vector<int> tmp = t;
                    tmp.insert(tmp.begin()+i,a);
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
};

int main()
{
    int num = 7486051;
    Solution s;
    if ( num > INT_MAX )
        cout << "The given number overflows " << endl;
    if ( s.reorderedPowerOf2(num) ) 
    {
        cout << num << " is power of 2 after reorder " << endl;
    }
    else {
        cout << num << " is power of 2 after reorder " << endl;
    }
}