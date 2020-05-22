/*
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
 */

// Time : O(MN)
// Space : O(MN)
class Solution_memo {
public:
    int dfs(int x, int y) {
        if (x == 0 || y == 0) {
            return 1;
        }

        if (memo[x][y] != -1) return memo[x][y];

        return memo[x][y] = dfs(x-1, y) + dfs(x, y-1);
    }

    int uniquePaths(int m, int n) {
        memo = vector(m, vector<int>(n, -1));
        return dfs(m-1,n-1);
    }
private:
    vector<vector<int>> memo;
};

// Time : O(MN)
// Space : O(MN)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
