// Problem Description 
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you 
 * like (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock 
 * before you buy again).
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * 
 * Example 2:
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 * engaging multiple transactions at the same time. You must sell before buying again.
 * 
 * Example 3:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

// This solution is a brute force approach employing recurison. 
// It calculates all possible sets of profits and choose the max profit. 
// O(n^n), O(n) 
// Note: it causes Time Limit Exceeded on Leetcode. 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }
    
    int calculate( vector<int> prices, int s ) 
    {
        if ( s >= prices.size() ) 
            return 0;
        int max = 0; 
        for ( int start = s; start < prices.size(); start++ ) {
            int maxprofit = 0;
            for ( int i = start + 1; i  < prices.size(); i++ ) {
                if ( prices[start] < prices[i] ) {
                    int profit = calculate(prices, i + 1 ) + prices[i] - prices[start];
                    if ( profit > maxprofit )
                        maxprofit = profit;
                }
            }
            
            if ( maxprofit > max )
                max = maxprofit;
        }
        return max;
    }
};


// This solution is based on the intuition that we can do every transcation on each pair of 
// valley and peak, since we are not limited by the number of transactions. 
// O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() < 2 ) 
            return 0;
        int valley = prices[0];
        int peak = prices[0];
        int i = 0, maxprofit = 0; 
        while ( i < prices.size() - 1 ) {
            while ( i < prices.size() - 1 && prices[i] >= prices[i+1] ) 
                i++; 
            valley = prices[i];
            while ( i < prices.size() - 1  && prices[i] <= prices[i+1] ) 
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        } 
        
        return maxprofit;
    }  
};

// This solution actually has the same idea with the above one but introduces a slight optimization 
// The above solution makes transactions only at valley and peak points, while this solution makes a 
// transaction as long as there is profit. Though it shares the same idea, it will need more transactions 
// than the above solution. 
// O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for ( int i = 1; i < prices.size(); i++ ) 
            if ( prices[i] > prices[i-1] ) 
                maxprofit += prices[i] - prices[i-1];
        return maxprofit;
    }  
};