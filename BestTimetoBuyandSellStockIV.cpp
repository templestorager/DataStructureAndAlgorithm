// Problem Description 
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * Example 1:
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * 
 * Example 2:
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 *              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 */

// This is actually a generized proble for k = 2. 
// But we need to consider the case where the number of transactions could be large than the total days, 
// in this case it defaults to the unlimited transactions. 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if ( prices.size() < 2 ) 
            return 0;
        if ( k >= prices.size() )
            return solveMaxProfit(prices);
        int global[k+1] = {0};
        int local[k+1] = {0};
        for ( int i = 0; i < prices.size() - 1; i ++ ) {
            int diff = prices[i+1] - prices[i];
            for ( int j = k; j >= 1; j-- ) {
                local[j] = max(global[j-1],local[j]) + diff;
                global[j] = max(global[j],local[j]);
            }
        }
        
        return global[k];
    }
    
    int solveMaxProfit( vector<int> prices) 
    {
        int maxprofit = 0;
        for ( int i = 1; i < prices.size(); i++ ) {
            if ( prices[i] > prices[i-1] )
                maxprofit += prices[i] - prices[i-1];
        }
        return maxprofit;
    }
};