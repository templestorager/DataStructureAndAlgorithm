// Problem Description 
/*
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * 
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note:  
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 */

// Assume the current ugly num is N, then the next ugly number should be the min of (2*N, 3*N,5*N)
// This solution uses priority queue to help draw the next ugly number. 
// Note that, the c++ priority queue retains the largest number at the top by default, i.e., big heap. 
// so we need to change the comparsion function object. 
// Also note that we got to use "long" to avoid OJ overflow. 
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>, greater<long>> pq; 
        long res;
        pq.push(1);
        for ( int i = 1; i <= n; i++  ) {
            res = pq.top();
            pq.pop();
            while ( !pq.empty() && res == pq.top() ) { 
                pq.pop();
            }
            pq.push(res*2);
            pq.push(res*3);
            pq.push(res*5);
        }
        
        return res;
    }
};

// This solution based on the fact that the serie of ugly num can be perceived from three lists 
// The three indexes are used to denote from whic list the ugly number is actually from. 
// O(n),O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglynums(1,1);
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while ( uglynums.size() < n ) {
            int m2 = uglynums[idx2] * 2, m3 = uglynums[idx3] * 3, m5 = uglynums[idx5] * 5;
            int cur = min(min(m2,m3),m5);
            if ( cur == m2 ) 
                idx2++;
            if ( cur == m3 )
                idx3++;
            if ( cur == m5 )
                idx5++;
            uglynums.push_back(cur);
        }
        
        return uglynums.back();
    }
};