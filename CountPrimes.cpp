// Problem Description 
/*
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */

// This solution is based on the Sieve of Eratosthenes algorithm. 
// which initializes an array to be true and gradually set those multiples of integers to be false, 
// then as it sequentially checks the numbers, if it is not to false then it is a prime number and 
// sets all its multiples

class Solution {
public:
    int countPrimes(int n) {
        int count = 0; 
        vector<bool> num(n,true);  // 0..n-1
        for ( int i = 2; i < n; i++  ) {
            if ( num[i] ) {
                count++;
                for ( int j = 2; j * i < n; j++ ) {
                    num[j*i] = false;
                }
            }
        }
        
        return count;
    }
};

// This is a brute force solution, which checks whether each of the numbers is prime or not. 
// O(n^2), O(1)
class Solution {
public:
    int countPrimes(int n) {
        int count = 0; 
        for ( int i = 2; i < n; i++  ) 
            count += IsPrime(i);
        return count;
    }

    int IsPrime( int n ) 
    {
        // because at least one of the factors must be less than sqrt(n)
        for ( int i = 2; i <= sqrt(n); i++ ) {  
            if ( n % i == 0 )
                return false;
        }
        
        return true;
    }
};