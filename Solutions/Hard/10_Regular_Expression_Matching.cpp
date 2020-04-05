/*
 Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        // Solution 1 --> Will give time out
        //return recursion(s, p);

        // Solution 2 --> Memoization
        if (p.empty())
            return s.empty();

        dp = vector(s.size()+1, vector<int>(p.size()+1, -1));
        return isMatch(s, p, 0, 0);
    }
private:
    vector<vector<int>> dp;

    bool isMatch(string &s, string &p, int si, int pi) {
        if (pi == p.size())
            return si == s.size();

        if (dp[si][pi] != -1)
            return dp[si][pi];

        bool first_match = (si < s.size()) &&
            (s[si] == p[pi] || p[pi] == '.');

        bool ans;
        if (pi+1 < p.size() && p[pi+1] == '*') {
            // Try Removing two chars from pattern , or
            // then firstMatch should be true and try removing first char from s.
            ans = isMatch(s, p, si, pi+2) ||
                (first_match && (isMatch(s, p, si+1, pi)));
        } else {
            //try removing first char from s and p
            ans = first_match && (isMatch(s, p, si+1, pi+1));
        }

        dp[si][pi] = ans;
        return ans;
    }

    bool recursion(string s, string p) {
        if (p.empty())
            return s.empty();

        bool first_match = !s.empty() &&
            (s[0] == p[0] || p[0] == '.');

        if (p.size() >= 2 && p[1] == '*') {
            // Try Removing two chars from pattern , or
            // then firstMatch should be true and try removing first char from s.
            return recursion(s, p.substr(2)) ||
                (first_match && (recursion(s.substr(1), p)));
        } else {
            //try removing first char from s and p
            return first_match && (recursion(s.substr(1), p.substr(1)));
        }
    }
};
