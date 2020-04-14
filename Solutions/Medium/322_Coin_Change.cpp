/*
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
 */

// Time : O(N*K)
// Space : O(N*K)

class Solution {
public:
    long int minCoins(vector<int>& coins, int n, int amount,vector<vector<int>> &dp) {
        if (amount < 0)
            return INT_MAX;
        if (amount == 0)
            return 0;
        if (n == 0)
            return INT_MAX;

        if (dp[n][amount] != -1)
            return dp[n][amount];

        long int ans = INT_MAX;
        if (amount >= coins[n-1]) {
            ans = 1 + minCoins(coins, n, amount-coins[n-1], dp);
        }

        ans = min(ans, minCoins(coins, n-1, amount,dp));

        return dp[n][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1 , -1));
        int res = minCoins(coins, coins.size(), amount,dp) ;
       return  res >= INT_MAX ? -1 : res;
    }
};

// Time : O(N*K)
// Space : O(N*K)

class Solution_DP {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1 , INT_MAX));
       for(int i=0; i<=n;i++)
           dp[i][0] = 0;

       for(int i=1; i<=amount;i++)
           dp[0][i] = INT_MAX;

        for(int i=1; i<=n;i++) {
            for(int j=1; j<=amount; j++) {
                if ( j >= coins[i-1]) {
                    dp[i][j] = dp[i][j-coins[i-1]] == INT_MAX ? INT_MAX : 1 + dp[i][j-coins[i-1]];
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
       return  dp[n][amount] == INT_MAX ? -1 :  dp[n][amount];
    }
};


// TIME: O(N*M)
// Space: O(M) // M is amount

class Solution_memo {
public:
    long int minCoins(vector<int>& coins, int amount, vector<int> &dp) {
        if (amount < 0)
            return INT_MAX;
        if (amount == 0)
            return 0;


        if (dp[amount] != -1)
            return dp[amount];

         int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            if (amount >= coins[i]) {
                int res = minCoins(coins, amount-coins[i], dp);
                if (res != INT_MAX)
                    ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1 , -1);
        int res = minCoins(coins, amount,dp) ;
       return  res >= INT_MAX ? -1 : res;
    }
};

// TIME: O(N*M)
// Space: O(M) // M is amount
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       vector<int> dp(amount+1 , INT_MAX);

        dp[0] = 0;
        for(int k=1; k<=amount;k++) {
           for(int i=0; i<coins.size(); i++) {
                if (k >= coins[i]) {
                    int res = dp[k-coins[i]];
                    if (res != INT_MAX)
                        dp[k] = min(dp[k], 1 + res);
                }
            }
       }
       return dp[amount] >= INT_MAX ? -1 : dp[amount];
    }
};

