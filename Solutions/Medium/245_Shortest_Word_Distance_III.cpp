/*
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
 */

//Time : O(N)
//Space : O(1)

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (words.size() < 2)
            return INT_MAX;

        int result = INT_MAX;

        if (word1 == word2) {
            int prevIndex = -1;
            for(int i=0; i<words.size();i++) {
                if (words[i] == word1) {
                    if (prevIndex != -1)
                        result = min(result, i - prevIndex);
                    prevIndex = i;
                }
            }
            return result;
        }

        int prevIndex1 = -1;
        int prevIndex2 = -1;
        for(int i=0; i<words.size();i++) {
            if (words[i] == word1) {
                    prevIndex1 = i;
            }
            if (words[i] == word2) {
                    prevIndex2 = i;
            }
            if (prevIndex1 != -1 && prevIndex2 != -1)
                result = min(result, abs(prevIndex1 - prevIndex2));
        }
        return result;
    }
};
