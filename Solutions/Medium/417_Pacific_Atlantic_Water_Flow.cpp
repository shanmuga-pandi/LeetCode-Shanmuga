/*
 Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
 
 */

// Time : O(M.N)
// Space : O(M.N)

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        int m = matrix.size();
        if (m == 0)
            return result;
        int n = matrix[0].size();
        if (n == 0)
            return result;
        vector<vector<bool>> pacific(m , vector<bool>(n, false));
        vector<vector<bool>> atlantic(m , vector<bool>(n, false));
        queue<pair<int,int>> pacific_queue;
        queue<pair<int,int>> atlantic_queue;
        // Add vertical lines
        for(int i=0; i<m;i++) {
            pacific[i][0] = true;
            pacific_queue.push({i,0});
            atlantic[i][n-1] = true;
            atlantic_queue.push({i, n-1});
        }
        // Add horizontal lines
        for(int i=0; i<n;i++) {
            pacific[0][i] = true;
            pacific_queue.push({0,i});
            atlantic[m-1][i] = true;
            atlantic_queue.push({m-1,i});
        }

        bfs(matrix, pacific_queue, pacific);
        bfs(matrix, atlantic_queue, atlantic);
        for(int i=0; i<m;i++) {
            for(int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
private:
    void bfs(vector<vector<int>>& matrix, queue<pair<int,int>> &queue, vector<vector<bool>>& visited) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dir[][2] = { {-1,0} , {0,1}, {1,0}, {0,-1}};
        while(!queue.empty()) {
            auto [x,y] = queue.front();
            queue.pop();
            for(int d=0; d<4; d++) {
                int i= x+dir[d][0];
                int j=y+dir[d][1];
                if(i<0 || i>=m || j<0 || j>=n)
                    continue;
                if(visited[i][j] || matrix[i][j] < matrix[x][y])
                    continue;
                visited[i][j] = true;
                queue.push({i,j});
            }
        }
    }
};
