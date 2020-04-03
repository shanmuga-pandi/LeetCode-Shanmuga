/*
 Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 */

class Solution {
public:
    int  longestPalindromeSubseq(string &s, int l, int r, vector<vector<int>> &dp) {
        if (r < l)
            return 0;
        
        if (r == l)
            return 1;
        
        if (dp[l][r] != -1)
            return dp[l][r];
        
        int res;
        if (s[l] == s[r])
            res = longestPalindromeSubseq(s, l+1, r-1, dp) + 2;
        else
            res = max(longestPalindromeSubseq(s, l+1, r, dp),
                     longestPalindromeSubseq(s, l, r-1, dp));
        dp[l][r] = res;
        return res;
    }
    
    int longestPalindromeSubseq(string s) {
       int n = s.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));
       int res = longestPalindromeSubseq(s, 0, n-1, dp);
       // cout << res;
       return res;
    }
};
