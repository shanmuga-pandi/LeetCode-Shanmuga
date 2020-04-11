/*
 There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 
Follow up:
Could you solve it in O(nk) runtime?
 */


// Solution 1 : Memoization

class Solution {
public:
    int minCost(vector<vector<int>>& costs, int n, int color, int k) {
        if (n == 0)
            return 0;
        
        if (dp[n][color] != -1) {
            return dp[n][color];
        }
        
        int minResult = INT_MAX;

        for(int c = 0; c < k; c++) {
            if (c != color)
                minResult = min(minResult, minCost(costs, n-1, c, k) + costs[n-1][c]);
        }
        
        dp[n][color] = minResult;
        return dp[n][color];
    }
                
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();
        if (k == 0)
            return 0;
        if (k == 1 && n == 1)
            return costs[0][0];
        dp = vector(n + 1, vector<int>(k, -1));

        int result = INT_MAX;
        for(int i=0; i<k;i++) {
            result = min(result, minCost(costs, n-1, i, k) + costs[n-1][i]);            
        }
        return result;
    }
private:
    vector<vector<int>> dp;
};

// Solution 2 : DP
class Solution_DP {
public:
    
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();
        if (k == 0)
            return 0;
        if (k == 1 && n == 1)
            return costs[0][0];
        
        vector<vector<int>> dp = vector(n + 1, vector<int>(k, INT_MAX));
        for(int i=0; i<k;i++) {
            dp[0][i] = 0;            
        }
        
        for(int i=1; i<=n; i++) {
            for(int color=0; color<k; color++) {
                for(int c = 0; c < k; c++) {
                    if (c != color)
                        dp[i][color] = min(dp[i][color], dp[i-1][c] + costs[i-1][c]);
                }
            }
        }
        int result = INT_MAX;
        for(int i=0; i<k;i++) {
            result = min(result, dp[n][i]);            
        }
        return result;
    }
};
