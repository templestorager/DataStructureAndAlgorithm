// Problem Description
/*
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
*/

#include <iostream> 
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;


// We should see that the status of each element includes the differences relative to each and every of 
// the elements before it. Therefore, we can use dynamic programming to calculate the slices. 
// For each current element, we need to remember how many slices there are corresponding to each possible difference. 
// For each prior element, we first calculate the difference between it and the current element. And if there is 
// already any subarray having the same difference, then it means addition the current element would result in at 
// least three elements having the same difference, which is a qualified "arithmetic slice". So we update the global 
// sum and then update the difference record for the current element. 

#if 0
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), sum = 0;
        if ( n < 3 )
            return sum;
        vector<unordered_map<int,int>> dp(n);
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < i; j++ )
            {
                long delta = (long)A[i] - A[j];
                if ( delta > INT_MAX || delta < INT_MIN )
                    continue;
                int diff = (int) delta;
                dp[i][diff]++;
                if ( dp[j].count(diff) )
                {
                    sum += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        
        return sum;
    }
};
#endif

// This solution has the same idea as the above solution, but it also records all the slices. 
#if 1
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), sum = 0;
        if ( n < 3 )
            return sum;
        vector<unordered_map<int,vector<vector<int>>>> dp(n);
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < i; j++ )
            {
                long delta = (long)A[i] - A[j];
                if ( delta > INT_MAX || delta < INT_MIN )
                    continue;
                int diff = (int)delta;
                dp[i][diff].push_back({A[j],A[i]});
                if ( dp[j].count(diff) )
                {
                    for ( auto it = dp[j][diff].begin(); it != dp[j][diff].end(); it++ )
                    {
                        vector<int> tmp(*it);
                        tmp.push_back(A[i]);
                        dp[i][diff].push_back(tmp);
                    }
                }
            }
        for ( int i = 0; i < n; i++ )
        {
            for ( auto it = dp[i].begin(); it != dp[i].end(); it++ )
            {
                for ( int j = 0; j < it->second.size(); j++ )
                {
                    if ( it->second[j].size() > 2 )
                    {
                        sum++;
                        int k;
                        cout <<"["; 
                        for ( k = 0; k < it->second[j].size() - 1; k++ )
                            cout<< it->second[j][k]<< " ";
                        cout<< it->second[j][k] << "]" <<endl;
                    }
                }
            }
        }
        
        return sum;
    }
};
#endif 

int main()
{
    vector<int> data = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // [1,2,3], [2,3,4], [1,2,3,4]
    Solution s;
    int slices = s.numberOfArithmeticSlices(data);
    cout << "Total number of slices is " << slices << endl;
}