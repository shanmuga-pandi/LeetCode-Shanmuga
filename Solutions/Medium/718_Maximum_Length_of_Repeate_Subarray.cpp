/*
 Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
 

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
 */

// Solution : Memoization
// Time : O(MN)
// Space : O(MN)

class Solution_memo {
public:
    int max_result = 0;
    int findLength(vector<int>& A, vector<int>& B, int M, int N, vector<vector<int>> &dp) {
        if (M == 0 || N == 0)
            return 0;
        int ans = 0;
        if (dp[M][N] != -1)
            return dp[M][N];

        if (A[M-1] == B[N-1])
            ans = 1 + (findLength(A,B,M-1, N-1, dp));

        findLength(A,B,M, N-1,dp);
        findLength(A,B,M-1, N,dp);

        max_result = max(max_result, ans);
        dp[M][N] = ans;
        return ans;
    }
    int findLength(vector<int>& A, vector<int>& B) {
       vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, -1));
       findLength(A,B,A.size(),B.size(), dp);
       return max_result;
    }
};

// Solution DP
// Time : O(MN)
// Space :O(MN)

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
       vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));
        int m = A.size();
        int n = B.size();
       for(int i=0; i<=m; i++)
           dp[i][0] = 0;
        for(int i=0; i<=n; i++)
           dp[0][i] = 0;
        int max_result = 0;
        for(int i=1;i<=m;i++) {
            for(int j=1; j<=n; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max_result = max(max_result, dp[i][j]);
                }
            }
        }
       return max_result;
    }
};
