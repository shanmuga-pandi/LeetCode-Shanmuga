/*
 Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
 
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    bool isOneDiff(const string &a, const string &b) {
        bool diffFound = false;
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                if (diffFound)
                    return false;
                diffFound = true;
            } else {
                i++;
            }
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        map<int, unordered_set<string>> hashmap;
        queue<vector<string>> q;
        for(string &word : words) {
            hashmap[word.size()].emplace(word);
        }
        int maxResult = 0;
        unordered_set<string> seen;
        for(auto &it : hashmap) {
            auto &wordsList = it.second;
             for(const string &word : wordsList) {
                if (seen.count(word) == 0) {
                    //cout << word << "\n";
                    seen.emplace(word);
                    q.push({word});
                    while(!q.empty()) {
                        vector<string> list = q.front();
                        q.pop();
                        maxResult = max(maxResult, (int) list.size());
                        string lastword = list[list.size()-1];
                        //cout << "size " << list.size() << "\n";

                        unordered_set<string> &nextList = hashmap[lastword.size()+1];
                        for(auto &nextword : nextList) {
                            if (seen.count(nextword) == 0 && isOneDiff(lastword, nextword)) {
                                seen.emplace(nextword);
                                vector<string> copylist = list;
                                copylist.push_back(nextword);
                                q.push(copylist);
                            }
                        }
                    }
                }
            }
        }
        return maxResult;
    }
};
