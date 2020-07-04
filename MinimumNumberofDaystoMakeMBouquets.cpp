// Problem Description 
/*
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here's the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
Example 4:

Input: bloomDay = [1000000000,1000000000], m = 1, k = 1
Output: 1000000000
Explanation: You need to wait 1000000000 days to have a flower ready for a bouquet.
Example 5:

Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
Output: 9
 

Constraints:

bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n

*/

#include <iostream>
#include <vector>
using namespace std;


// Basically, for each day we could check the number of bouquets (i.e., continuous amount of elements being less than the day )
// If this day satifies the requirments, then this is the answer. 
// So we could find the mini day and the max day, and then check the whether the value is vald or not. If anyday satifies, then it is the answer 
// This solution has an O(n) complexity and would cause time limit exceeds 
// To improve, we can use use binary search to check the days between [minday,maxday]
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ( bloomDay.size() == 0 || m == 0 || k == 0 )
        {
            return 0;
        }
        if ( bloomDay.size() < m * k ) 
            return -1;
        int minday = bloomDay[0];
        int maxday = bloomDay[0];
        for ( int i = 1; i < bloomDay.size(); i++ )
        {
            minday = min(minday,bloomDay[i]);
            maxday = max(maxday,bloomDay[i]);
        }
        
        for ( int i = minday; i <= maxday; i++ )
        {
            if ( IsValid(bloomDay, m, k, i) )
            {
                return i;
            }
        }
        return -1;
    }
    
    int IsValid( vector<int> &bloomDay, int m, int k, int d ) 
    {
        int countm = 0, countk = 0;
        for ( int i = 0; i < bloomDay.size(); i++ )
        {
            if ( bloomDay[i] <= d )
            {
                countk++;
                if ( countk == k ) 
                {
                    countm++;
                    countk = 0;
                }
            }
            else 
            {
                countk = 0;
            }
        }
        
        return countm >= m;
    }
};

// This solution uses binary search to explore the days' eligibility
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ( bloomDay.size() == 0 || m == 0 || k == 0 )
        {
            return 0;
        }
        if ( bloomDay.size() < m * k ) 
            return -1;
        int minday = bloomDay[0];
        int maxday = bloomDay[0];
        int ans = -1;
        for ( int i = 1; i < bloomDay.size(); i++ )
        {
            minday = min(minday,bloomDay[i]);
            maxday = max(maxday,bloomDay[i]);
        }
        
        while ( minday <= maxday )
        {
            int mid = minday + (maxday-minday) / 2;
            if ( IsValid(bloomDay, m, k, mid) )
            {
                ans = mid;
                maxday = mid - 1;
            }
            else 
            {
                minday = mid+1;
            }
        }
        return ans;
    }
    
    int IsValid( vector<int> &bloomDay, int m, int k, int d ) 
    {
        int countm = 0, countk = 0;
        for ( int i = 0; i < bloomDay.size(); i++ )
        {
            if ( bloomDay[i] <= d )
            {
                countk++;
                if ( countk == k ) 
                {
                    countm++;
                    countk = 0;
                }
            }
            else 
            {
                countk = 0;
            }
        }
        
        return countm >= m;
    }
};

/*
int main()
{
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    Solution s;
    s.minDays( bloomDay, m, k );
}
*/