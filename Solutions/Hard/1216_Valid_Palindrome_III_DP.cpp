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

/*
 The idea is to find the longest palindromic subsequence(lps) of the given string.
|lps - original string| <= k,
then the string is k-palindrome.

Eg:

One of the lps of string pqrstrp is prsrp.
Characters not contributing to lps of the
string should be removed in order to make the string palindrome. So on removing q and s (or t) from pqrstrp,
string will transform into a palindrome.

 */

class Solution {
public:
    int lcs(string &s1, string &s2, int m, int n) {
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    bool isValidPalindrome(string s, int k) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        int lps = lcs(s, rev, n, n);
        return (n - lps) <= k;
    }
};


