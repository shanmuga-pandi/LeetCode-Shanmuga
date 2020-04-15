/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 */

// Memoization
// Time : O(N^2)
// Space : O(N)
class Solution_memo {
public:
    bool wordBreak(string &s, unordered_set<string>& dict, int start, vector<int> &memo) {
        if (start == s.size())
            return true;

        if (memo[start] != -1)
            return memo[start] == 1;

        string sub;
        for(int i=start; i<s.size(); i++) {
            sub += s[i];
            if (dict.count(sub) > 0) {
                if (wordBreak(s, dict, i+1, memo)) {
                    memo[start] = 1;
                    return true;
                }
            }
        }
        memo[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
            return false;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size()+1, -1);
        return wordBreak(s, dict, 0, memo);
    }
};

// Memoization
// Time : O(N^2)
// Space : O(N)

class Solution_top_down {
public:
    bool wordBreak(string &s, unordered_set<string>& dict, int end, vector<int> &memo) {
        if (end == 0)
            return true;

        if (memo[end] != -1)
            return memo[end] == 1;

        string sub;
        for(int i=end; i>0; i--) {
            sub = s[i-1] + sub;
            if (dict.count(sub) > 0) {
                if (wordBreak(s, dict, i-1, memo)) {
                    memo[end] = 1;
                    return true;
                }
            }
        }
        memo[end] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
            return false;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size()+1, -1);


        return wordBreak(s, dict, s.size(), memo);
    }
};



// DP
// Time : O(N^2)
// Space : O(N)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
            return false;
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> memo(n+1, false);
        memo[0] = true;
        for(int k=1; k<=n; k++) {
            string sub;
            for(int i=k; i>0; i--) {
                sub = s[i-1] + sub;
                if (dict.count(sub) > 0) {
                    if (memo[i-1]) {
                        memo[k] = true;
                        break;
                    }
                }
            }
        }

        return memo[n];
    }
};
