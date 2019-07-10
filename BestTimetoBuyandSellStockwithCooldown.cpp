// Problem Description 
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you 
 * like (ie, buy one and sell one share of the stock multiple times) with the following 
 * restrictions:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock 
 * before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 * Example:
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */

// This is a dynamical programming problem involving multip states
// The key to understand the meaning of the three auxiliary arrays
// e.g., buy[i] indidcates the maximum profix on day i with the last action being "buy", 
// which not necessarily has to happen on day i. 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() < 2 ) 
            return 0;
        int days = prices.size();
        int buy[days],sell[days],rest[days];
        buy[0] = -prices[0];
        sell[0] = 0;
        rest[0] = 0;
        for ( int i = 1; i < days; i++ ) {
            buy[i] = max(buy[i-1],rest[i-1] - prices[i]);
            sell[i] = max( buy[i-1] + prices[i], rest[i-1] );
            sell[i] = max( sell[i], sell[i-1] );
            rest[i] = max( rest[i-1], sell[i-1]);
            rest[i] = max(rest[i], buy[i-1] );
        }    
        return max(rest[days-1],sell[days-1]);
    }
};

// We can use only two arrays: 
// buy[i] = max(buy[i-1],sell[i-2]-price)   // becase we must cooldown after a sell, thus sell[i-2]
// sell[i] = max(sell[i-1],buy[i-1] + price)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_buy, buy = INT_MIN, pre_sell = 0, sell = 0;
        for ( int price : prices ) { 
            pre_buy = buy; 
            buy = max(pre_buy,pre_sell-price);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }        
        return sell;
    }
};