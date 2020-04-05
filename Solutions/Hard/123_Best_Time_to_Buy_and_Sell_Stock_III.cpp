/*
 Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

class Solution_DP {
public:
    int maxProfit(vector<int>& prices, int index, bool lastPurchased, int k) {
        if (index == prices.size())
            return 0;
        
        if (k < 0)
            return 0;
        
        if (dp[index][lastPurchased][k] != -1)
            return dp[index][lastPurchased][k];
        
         int result = 0;
        
        // Check with skip
         result = maxProfit(prices, index+1, lastPurchased,k);
        
        // if lastPurchased is false, then I can buy and go
        if (lastPurchased == 0) {
            result = max(result, maxProfit(prices, index+1, true, k) - prices[index]);
        } else { // if lastPurchased is true, I can sell and go
            result = max(result, maxProfit(prices, index+1, false, k-1) + prices[index]);
        }        
        
        dp[index][lastPurchased][k] = result;
        return result;
    }
    
    int maxProfit(vector<int>& prices) {
        dp = vector(prices.size(), vector(2, vector<int>(2, -1)));
        return maxProfit(prices, 0, 0, 1);
    }
private:
    vector<vector<vector<int>>> dp;
};
