/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
 */

// Time : O(n^3). Size of recursion tree can go up to n^2. The creation of list takes n time.
// Space : O(n^3)The depth of the recursion tree can go up to nn and each activation record can contains a string list of size n

class Solution {
public:
    bool wordBreak(string &s, unordered_set<string>& dict, int end, vector<int> &memo, vector<vector<string>> &results)  {
        if (end == 0)
            return true;

        if (memo[end] != -1)
            return memo[end] == 1;

        string sub;
        for(int i=end; i>0; i--) {
            sub = s[i-1] + sub;
            if (dict.count(sub) > 0) {
                if (wordBreak(s, dict, i-1, memo, results)) {
                    if (results[i-1].empty()) {
                        results[end].push_back(sub);
                    } else {
                        for(string& list : results[i-1]) {
                            results[end].push_back(list + " " + sub);
                        }
                    }
                    memo[end] = 1;
                    //return true;
                }
            }
        }
        memo[end] = memo[end] == 1;
        return memo[end];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<vector<string>> results(n+1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size()+1, -1);


        bool res = wordBreak(s, dict, s.size(), memo, results);
        return results[s.size()];
    }
};


// Time : O(n^3). Size of recursion tree can go up to n^2. The creation of list takes n time.
// Space : O(n^3)The depth of the recursion tree can go up to nn and each activation record can contains a string list of size n


// Simplified solution
class Solution {
public:
     vector<string> wordBreak(string &s, unordered_set<string>& dict, int end, unordered_map<int, vector<string>> &memo)  {
        if (end == 0)
            return {""};

        if (memo.count(end) > 0)
            return memo[end];

        vector<string> res;
        string sub;
        for(int i=end; i>0; i--) {
            sub = s[i-1] + sub;
            if (dict.count(sub) > 0) {
                  vector<string> results = wordBreak(s, dict, i-1, memo);    
                    for(string& list : results) {
                        res.push_back(list == "" ? sub : list + " " + sub);
                    }
            }
        }
        memo[end] = res;
        return memo[end];
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        return wordBreak(s, dict, s.size(), memo);
    }
};
