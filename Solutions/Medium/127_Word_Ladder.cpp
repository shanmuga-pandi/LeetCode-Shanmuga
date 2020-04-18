/*
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */

// Time : O(N)
// Space : O(N)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0)
            return 0;
        queue<string> q;
        unordered_set<string> seen;
        q.push(beginWord);
        seen.emplace(beginWord);
        int count = 0;
	// BFS
        while(!q.empty()) {
            int qSize = q.size();
            count++;
            for(int s = 0; s < qSize; s++) {
                string currWord = q.front();
                q.pop();
                if (currWord == endWord)
                    return count;
                
                for(int i=0; i<currWord.size();i++) {
                    char prevC = currWord[i];
                    for(char c='a'; c<='z';c++) {
                        currWord[i] = c;
                        if (dict.count(currWord) != 0 && seen.count(currWord) == 0) {
                            q.push(currWord);
                            seen.emplace(currWord);
                        }
                    }
                     currWord[i] = prevC;
                }
            }
        }
        return 0;
    }
};
