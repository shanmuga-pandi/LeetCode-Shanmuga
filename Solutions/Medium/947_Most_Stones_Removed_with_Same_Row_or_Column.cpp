/*
 On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
 */

// Time : O(N^2)
// Space : O(N^2)

class Solution {
public:
    void clearStones(vector<vector<int>>& stones, int k, unordered_set<int> &seen) {
        int x = stones[k][0];
        int y = stones[k][1];

        for(int i=0; i<stones.size(); i++) {
            int nextX = stones[i][0];
            int nextY = stones[i][1];
            if ((nextX == x || nextY == y) && seen.count(i) == 0) {
                seen.insert(i);
                clearStones(stones, i, seen);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int> seen;
        int no_of_islands = 0;
        for(int i=0; i<stones.size(); i++) {
            if (seen.count(i) == 0) {
                seen.insert(i);
                clearStones(stones, i, seen);
                no_of_islands++;
            }

        }
        return stones.size() - no_of_islands;
    }

};

// Need Union Find

