/*
 Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

// Time : O(N)
// Space : O(N)
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            words_map[words[i]].emplace(i);
        }
    }

    int shortest(string word1, string word2) {
        int shortest = INT_MAX;
        set<int> &word1_list = words_map[word1];
        set<int> &word2_list = words_map[word2];

        auto word1_it = word1_list.begin();
        auto word2_it = word2_list.begin();
        while(word1_it != word1_list.end() && word2_it != word2_list.end()) {
            shortest = min(shortest, abs(*word1_it - *word2_it));
            if (*word1_it < *word2_it)
                word1_it++;
            else
                word2_it++;
        }
        return shortest;
    }
private:
    unordered_map<string, set<int>> words_map;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
