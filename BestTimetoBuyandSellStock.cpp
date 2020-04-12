// Problem Description 
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of 
 * the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 *  */

// This solution uses brute force to calcalute the profit of each and every possible one-time transaction.
// O(n^2) O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for ( int i = 0; i < prices.size(); i++ ) {
            for ( int j = i + 1; j < prices.size(); j++ ) {
                if ( prices[j] - prices[i] > maxprofit )
                    maxprofit = prices[j] - prices[i];
            }
        }
        return maxprofit; 
    }
};

// This solution tries to find the smallest valley and maxprofit as we scan. 
// O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, smallest_valley = INT_MAX;
        for ( int i = 0; i < prices.size(); i++ ) { 
            if  ( prices[i] < smallest_valley ) 
                smallest_valley = prices[i];
            else if ( prices[i] - smallest_valley > maxprofit ) 
                maxprofit = prices[i] - smallest_valley;
        }
        
        return maxprofit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, minprice = INT_MAX;
        for ( auto p : prices )
        {
            if ( p < minprice )
            {
                minprice = p;
            }
            maxprofit = max(maxprofit,p-minprice);
        }
        
        return maxprofit;
    }
};