/*
 Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
 */

// Time : O(N⋅26 ^ L)
// Space : O(N⋅L+N⋅L/2)

class Solution {
public:
    void build_prefix_list(vector<string>& words) {
        // Build prefix list till max of word length
        int n = words[0].size();

        for(string &word: words) {
            for(int i=1; i<n;i++) {
                string prefix = word.substr(0, i);
                prefix_list[prefix].push_back(word);
            }
        }
    }

    void backtracking(vector<string>& words, int level, vector<string> &picked) {
       int n = words[0].size();
       if (level == n) {
           result.push_back(picked);
           return;
       }

       string prefix;
       for(int i=0; i<level; i++) {
           // look for symmetrix prefix
           prefix += picked[i][level];
       }

        // Find next possile string and do dfs
        list<string> &p_list = prefix_list[prefix];
        for(string s:p_list) {
            picked.push_back(s); // Try with this word
            backtracking(words,level+1,picked);
            picked.pop_back(); // Try without this word
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.size() == 0 || words[0].size() == 0)
            return result;

        build_prefix_list(words);

        vector<string> picked;
        for(string &word: words) {
            picked.push_back(word); // Try with this word
            backtracking(words,1,picked);
            picked.pop_back(); // Try without this word
        }
        return result;
    }
private:
    unordered_map<string, list<string>> prefix_list;
    vector<vector<string>> result;
};
