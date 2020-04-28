/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 */

// Time : O(mn ^ 2)
// Space : O(mn)
class Solution_recursion {
public:
    bool checkRowCol(vector<vector<char>>& matrix, int x, int y, int squareSize) {
        for(int i=1; i<=squareSize;i++) {
            if (matrix[x-i][y] == '0')
                return false;
            if (matrix[x][y-i] == '0')
                return false;
        }
        return true;
    }

    bool maxSquare(vector<vector<char>>& matrix, int x, int y, int squareSize) {
        max_result = max(max_result, squareSize+1);

        if (x >= m || y >= n)
            return true;

        if (x+1 < m && y+1 < n) {
            if (matrix[x+1][y+1] == '1' && checkRowCol(matrix, x+1, y+1, squareSize+1))
                return maxSquare(matrix, x+1, y+1, squareSize+1);
        }
        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        if (m == 0)
            return 0;
        n = matrix[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (matrix[i][j] == '1') {
                    maxSquare(matrix, i,j,0);
                }
            }
        }
        return max_result * max_result;
    }
private:
    int m;
    int n;
    int max_result;
};

// Time : O(MN)
// Space : O(MN)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int max_result = 0;
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max_result = max(max_result, dp[i][j]);
                }
            }
        }
        return max_result * max_result;
    }
};
