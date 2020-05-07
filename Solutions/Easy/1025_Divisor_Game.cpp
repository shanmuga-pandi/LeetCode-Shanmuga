/*
 Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:

1 <= N <= 1000
 */

// Time : O(1)
// Space : O(1)

// Solution 1: One line 

class Solution {
public:
    bool divisorGame(int N) {
        return N%2 == 0;
    }
};

// Solution 2: Memoization
// Time : O(N)
// Space : O(N)

// Memo
class Solution_MEMO {
public:
    bool canAliceWin(int N, int playerNo) {
        if (N==1) {
            return playerNo == 1;
        }

        if (memo[N][playerNo] != -1)
            return memo[N][playerNo];

        bool res;
        if (playerNo == 0) {
            res = false;
            for(int i=1; i<=N/2;i++) {
                if (N%i == 0)
                    res = res | canAliceWin(N-i, (playerNo+1)%2);
            }
        } else {
            res = true;
            for(int i=1; i<=N/2;i++) {
                if (N%i == 0)
                    res = res & canAliceWin(N-i, (playerNo+1)%2);
                if (!res)
                    break;
            }
        }
        memo[N][playerNo] = res;
        return res;
    }

    bool divisorGame(int N) {
        memo = vector(N+1, vector<int>(2, -1));
        return canAliceWin(N, 0);
    }
private:
    vector<vector<int>> memo;
};

