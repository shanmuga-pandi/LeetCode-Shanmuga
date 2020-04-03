/*
 Given a string s and an integer k, find out if the given string is a K-Palindrome or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
 

Constraints:

1 <= s.length <= 1000
s has only lowercase English letters.
1 <= k <= s.length
 */

class Solution {
public:
    int  minRemovals(string &s, int l, int r, vector<vector<int>> &dp) {
        if (r <= l)
            return 0;
        
        if (dp[l][r] != -1)
            return dp[l][r];
        
        int res;
        if (s[l] == s[r])
            res = minRemovals(s, l+1, r-1, dp);
        else
            res = min(minRemovals(s, l+1, r, dp),
                     minRemovals(s, l, r-1, dp)) + 1;
        dp[l][r] = res;
        return res;
    }
    bool isValidPalindrome(string s, int k) {
       int n = s.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));
       int res = minRemovals(s, 0, n-1, dp);
       // cout << res;
       return res <= k;
    }
};
