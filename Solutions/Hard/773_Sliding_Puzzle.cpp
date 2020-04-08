/*
 On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
 */

class Solution {
public:
    bool isSolved(vector<vector<int>>& board) {
        if (board[0][0] != 1)
            return false;
        if (board[0][1] != 2)
            return false;
        if (board[0][2] != 3)
            return false;
        if (board[1][0] != 4)
            return false;
        if (board[1][1] != 5)
            return false;
        if (board[1][2] != 0)
            return false;
        return true;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        set<vector<vector<int>>> seen;
        queue<vector<vector<int>>> q;
        q.push(board);
        seen.emplace(board);
        int moves = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                vector<vector<int>> curr = q.front();
                q.pop();
                if(isSolved(curr))
                    return moves;
                for(int i=0; i<2;i++) {
                    for(int j=0; j<3; j++) {
                        if (curr[i][j] == 0) {
                            if (i-1 >=0 ) { // Move Top
                                swap(curr[i][j] , curr[i-1][j]);
                                if (seen.count(curr) == 0) {
                                    q.push(curr);
                                    seen.emplace(curr);
                                }
                                swap(curr[i][j] , curr[i-1][j]);
                            }
                            if (j+1 < 3 ) { // Move Right
                                swap(curr[i][j] , curr[i][j+1]);
                                if (seen.count(curr) == 0) {
                                    q.push(curr);
                                    seen.emplace(curr);
                                }
                                swap(curr[i][j] , curr[i][j+1]);
                            }
                            if (i+1 < 2 ) { // Move Down
                                swap(curr[i][j] , curr[i+1][j]);
                                if (seen.count(curr) == 0) {
                                    q.push(curr);
                                    seen.emplace(curr);
                                }
                                swap(curr[i][j] , curr[i+1][j]);
                            }
                            if (j-1 >= 0 ) { // Move Left
                                swap(curr[i][j] , curr[i][j-1]);
                                if (seen.count(curr) == 0) {
                                    q.push(curr);
                                    seen.emplace(curr);
                                }
                                swap(curr[i][j] , curr[i][j-1]);
                            }
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
