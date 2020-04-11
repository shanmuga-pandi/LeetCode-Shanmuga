/*
 There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
             Minimum cost: 2 + 5 + 3 = 10.
 */

// Solution 1 : Memoization Solution
class Solution {
public:
    int minCost(vector<vector<int>>& costs, int n, int color) {
        if (n == 0)
            return 0;

        if (dp[n][color] != -1) {
            return dp[n][color];
        }

        if (color == 0) {
            return dp[n][color] = min(minCost(costs, n-1, 1) + costs[n-1][1],
                          minCost(costs, n-1, 2) + costs[n-1][2]);
        }
        if (color == 1) {
            return dp[n][color] = min(minCost(costs, n-1, 0) + costs[n-1][0],
                          minCost(costs, n-1, 2) + costs[n-1][2]);
        }
        return dp[n][color] = min(minCost(costs, n-1, 0) + costs[n-1][0],
                          minCost(costs, n-1, 1) + costs[n-1][1]);
    }

    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        dp = vector(n + 1, vector<int>(3, -1));

        return min(minCost(costs, n-1, 0) + costs[n-1][0],
                       min(minCost(costs, n-1, 1) + costs[n-1][1],
                          minCost(costs, n-1, 2) + costs[n-1][2]));
    }
private:
    vector<vector<int>> dp;
};


// Solution 2 : DP Solution
class Solution {
public:

    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        dp = vector(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;

        for(int i=1; i<=n; i++) {
            for(int color=0; color<3; color++) {
                if (color == 0) {
                    dp[i][color] = min(dp[i-1][1] + costs[i-1][1],
                          dp[i-1][2] + costs[i-1][2]);
                } else if (color == 1) {
                    dp[i][color] = min(dp[i-1][0] + costs[i-1][0],
                          dp[i-1][2] + costs[i-1][2]);
                } else {
                    dp[i][color] = min(dp[i-1][0] + costs[i-1][0],
                          dp[i-1][1] + costs[i-1][1]);
                }
            }
        }
        return min(dp[n][0],
                  min(dp[n][1], dp[n][2]));
    }
private:
    vector<vector<int>> dp;
};
