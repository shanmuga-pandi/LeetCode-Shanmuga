/*
 Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

// Solution Top - Down memoization

class Solution_Memo {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp = vector(m+1, vector<int>(n+1, -1));
        return minDistance(word1, word2, m , n);
    }
private:
    int minDistance(string &word1, string &word2, int i, int j) {
        if (i == 0 )
            return  j;

        if (j == 0 )
            return  i;

        //cout << i << j << "\n";
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (word1[i-1] == word2[j-1])
            ans = minDistance(word1, word2, i-1, j-1);
        else {
            ans = minDistance(word1, word2, i, j-1) + 1; //insertion
            ans = min(ans, minDistance(word1, word2, i-1, j) + 1); //deletion
            ans = min(ans, minDistance(word1, word2, i-1, j-1) + 1); //replace
        }
        dp[i][j] = ans;
        return ans;
    }
   vector<vector<int>> dp;
};


// Solution Bottom - Up DP

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) {
            dp[0][i] = i;
        }
        for(int i=1; i<=m; i++) {
            dp[i][0] = i;
        }
        for(int i=1; i<=m;i++) {
            for(int j=1; j<=n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i][j-1] + 1, dp[i-1][j] + 1), dp[i-1][j-1] +1);
                }
            }
        }
        return dp[m][n];
    }
};
