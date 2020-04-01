/*
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

Example:

Input: 4
Output: false
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be
             removed by your friend.
 */

/*
dp[i] represents if I am currently landing on i and taking a move (1 to 3) can I win or not.
Apparently dp[i] = !(dp[i-1] && dp[i-2] && dp[i-3]), why? Think you are on dp[4], and you can move 1 to 3 places, so if dp[3], dp[2] and dp[1] are all true means your opponent will win because it is your opponent's turn next, sodp[4] = false. Assume you are on dp[5], and you know dp[4] == false, so you will take 1 step and move to dp[4] and then your opponent lose.
*/

/*class Solution {
public:
    bool canWinNim(int playerNo, int rem) {
        if (rem <= 3)
            return playerNo == 0;

        int nextPlayer = (playerNo + 1) % 2;
        if (playerNo == 0) {
            return canWinNim(nextPlayer, rem - 1) ||
                canWinNim(nextPlayer, rem - 2) ||
                canWinNim(nextPlayer, rem - 3);
        }

        return canWinNim(nextPlayer, rem - 1) &&
                canWinNim(nextPlayer, rem - 2) &&
                canWinNim(nextPlayer, rem - 3);
    }

    bool canWinNim(int n) {
       return canWinNim(0, n);
    }
};*/

class Solution {
public:
     bool canWinNim(int n) {
         if (n >= 100000) // Maths Hack
             return (n % 4 != 0);
        if (n <= 3)
             return true;
        vector<bool> dp = vector<bool>(n + 1);
        dp[0] = false;
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;

        for(int i = 4; i <= n; i++) {
            dp[i] = !(dp[i-1] && dp[i-2] && dp[i-3]);
        }

        return dp[n];
    }
};
