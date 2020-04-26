/*
 Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

// Time : O(mn)
// Space : O(mn)

class Solution {
public:
    int maxLength(vector<vector<int>>& matrix, int x, int y,vector<vector<bool>> &visited, vector<vector<int>> &memo) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n)
            return 0;

        if (memo[x][y] != -1)
            return memo[x][y];

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = { 0, 1, 0, -1};

        int result = 0;
        for(int i=0; i<4;i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newY < 0 || newX >= m || newY >= n)
                continue;
            if (!visited[newX][newY] && matrix[x][y] > matrix[newX][newY]) {
                visited[newX][newY] = true;
                result = max(result, 1 + maxLength(matrix,newX,newY,visited, memo));
                visited[newX][newY] = false;
            }
        }
        memo[x][y] = result;
        return result;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int result = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = true;
                result = max(result, maxLength(matrix,i,j,visited, memo) + 1);
                visited[i][j] = false;
            }
        }
        return result;
    }

};
