/*
 Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        dp = vector(s.size()+1, vector<int>(p.size()+1, -1));
        return isMatch(s,p,0,0);
    }
private:
    bool isMatch(string &s, string &p, int si, int pi) {
        if (pi == p.size())
            return si == s.size();

        if (si == s.size()) {
            while(pi != p.size()) {
                if (p[pi++] != '*')
                    return false;
            }
            return true;
        }
        if (dp[si][pi] != -1)
            return dp[si][pi];

        bool firstMatch = si < s.size() &&
            (s[si] == p[pi] || p[pi] == '?');

        bool ans;
        if (p[pi] == '*') {
            ans = isMatch(s,p,si+1,pi) || isMatch(s,p,si,pi+1);
        } else {
            ans = firstMatch && isMatch(s,p,si+1,pi+1);
        }
        dp[si][pi] = ans;
        return ans;
    }
    vector<vector<int>> dp;
};



class Solution_Memoization {
public:
    bool isMatch(string s, string p) {
        if (s == p)
            return true;
        if (p == "*")
            return true;
        if (p.empty() || s.empty())
            return false;
        p = remove_duplicate_stars(p);
        dp = vector(s.size()+1, vector<int>(p.size()+1, -1));
        return isMatch(s,p,0,0);
    }
private:
    string remove_duplicate_stars(string& p) {
        string p1;
        p1.push_back(p[0]);
        for(int i=1; i<p.size(); i++) {
            if (p[i] != '*' || p1[p1.size()-1] != '*')
                p1.push_back(p[i]);
        }
        return p1;
    }
    bool isMatch(string &s, string &p, int si, int pi) {
        if (pi == p.size())
            return si == s.size();
        
        if (si == s.size()) {
            while(pi != p.size()) {
                if (p[pi++] != '*')
                    return false;
            }
            return true;
        }
        if (dp[si][pi] != -1)
            return dp[si][pi];
        
        bool firstMatch = si < s.size() && 
            (s[si] == p[pi] || p[pi] == '?');
        
        bool ans;
        if (p[pi] == '*') {
            ans = isMatch(s,p,si+1,pi) || isMatch(s,p,si,pi+1);
        } else {
            ans = firstMatch && isMatch(s,p,si+1,pi+1);
        }
        dp[si][pi] = ans;
        return ans;
    }
    vector<vector<int>> dp;
};


class Solution_DP {
public:
    bool isMatch(string &s, string &p) {
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=1; i<=n; i++) {
            dp[0][i] = p[i-1] == '*' && dp[0][i-1];
        }
        

        for(int i=1; i<=m;i++) {
            for(int j=1; j<=n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') ? dp[i-1][j-1] : false;
                }
            }
        }
        return dp[m][n];
    } 
};


