// Problem Description 
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock 
 * before you buy again).
 * 
 * Example 1:
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
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
 * 
 */

// This solution uses dynamical programming. 
// local[i][j] indicates the max profit on day i with a maximum of j transactions (0...j)
//             The iterative relation is: local[i][j] = local[i-1][j-1] + max(diff,0) ( day i - 1 has j- 1 transactions)
//                                        or 
//                                        local[i][j] = local[i-1][j] + diff; 
// global[i][j] indicates the global maximum profit on day i with a maximum of j transactions 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() < 2 ) 
            return 0;
        int days = prices.size(), global[days][3] = {0}, local[days][3] = {0};
        for ( int i = 1; i < days; i++ ) {
            int diff = prices[i] - prices[i-1];
            for ( int j = 1; j <= 2; j++ ) {
                local[i][j] = max(global[i-1][j-1],local[i-1][j] ) + diff;
                global[i][j] = max(local[i][j], global[i-1][j]);
            }
        }
        return global[days-1][2];
    }
};

// This solution improves over the above solutin by using one-dimensional arrays. 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() < 2 ) 
            return 0;
        int days = prices.size(), global[3] = {0}, local[3] = {0};
        for ( int i = 0; i < days-1; i++ ) {
            int diff = prices[i+1] - prices[i];
            for ( int j = 2; j >=1; j-- ) {
                local[j] = max(global[j-1],local[j]) + diff;
                global[j] = max(local[j],global[j]);
            }
        }
        
        return global[2];
    }
};