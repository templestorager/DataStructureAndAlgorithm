// Problem Description 
/*
 * Write a program to find the nth super ugly number.
 * Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of
 * size k.
 * 
 * Example:
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
 * super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 */

// This is the brute force solution, check each integrate util we find the n-the SGN
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if ( n == 1 ) 
            return 1;
        int sgn_num = 1;
        int num;
        for ( num = 2; sgn_num < n; num++ ) {
            if(IsSuperUglyNumber(num,primes)) {
                sgn_num++;
            }
        }
        return num-1;
    }
    
    bool IsSuperUglyNumber( int n, vector<int> &primes ) {
        for ( int i = 0; i < primes.size(); i++ ) {
            while( n % primes[i] == 0 )
                n /= primes[i];
        }
        return n == 1;
    }
};


// This solution uses priority queue.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long,vector<long>,greater<long>> pq;
        long res;
        pq.push(1);
        for ( int i = 1; i <= n; i++  ) {
            res = pq.top();
            pq.pop();
            while ( !pq.empty() && res == pq.top() ) {
                pq.pop();
            }
            for ( int i = 0; i < primes.size(); i++ ) {
                pq.push(res*primes[i]);
            }
        }
        return res;
    }
};

// Similar to the problem of ugly number with checking all given primes. 
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1), idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for ( int j = 0; j < primes.size(); j++ ) {
                if ( dp[idx[j]] * primes[j] <= dp[i] ) {
                    dp[i] = dp[idx[j]] * primes[j];
                }
            }
            for ( int j = 0; j < primes.size(); j++ ) {
                if ( dp[i] == dp[idx[j]] * primes[j] )
                    idx[j]++;
            }
        }
        return dp[n-1];
    }
}