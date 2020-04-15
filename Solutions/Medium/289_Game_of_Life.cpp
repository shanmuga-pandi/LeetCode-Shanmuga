/*
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 */

// Time : O(M*N)
// Space : O(1)
class Solution {
public:

    int countLiveNeighbours(vector<vector<int>>& board, int m, int n, int x, int y) {
        int deltas[8][2] = {
            {-1,0},{-1,1},{0,1},{1,1},
            {1,0},{1,-1},{0,-1},{-1,-1}
        };
        int count = 0;
        for(int i=0; i<8; i++) {
            int newX = x + deltas[i][0];
            int newY = y + deltas[i][1];
            if (newX < 0 || newX >= m || newY<0 || newY >= n)
                continue;
            if (abs(board[newX][newY]) == 1)
                count++;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
      int m = board.size();
      if (m == 0)
          return;
        int n = board[0].size();
        for(int i=0; i<m;i++) {
            for(int j=0; j<n; j++) {
                int count = countLiveNeighbours(board, m, n, i, j);
                if (abs(board[i][j]) == 1) {
                    if (count < 2 || count > 3)
                        board[i][j] = -1;
                } else {
                    if (count == 3)
                        board[i][j] = 2;
                }
            }
        }

        for(int i=0; i<m;i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == -1) {
                        board[i][j] = 0;
                }
                if (board[i][j] == 2) {
                        board[i][j] = 1;
                }
            }
        }
    }
};
