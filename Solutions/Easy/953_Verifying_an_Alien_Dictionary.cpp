/*
 In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
 */


/*
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, vector<char>> Graph;
        unordered_map<char, int> indegrees;

        // Build Graph
        for(int i=1; i<words.size();i++) {
            string &prev_word = words[i-1];
            string &curr_word = words[i];
            int len = min(prev_word.size(), curr_word.size());
            for(int j=0; j<len; j++) {
                if (prev_word[j] != curr_word[j]) {
                    Graph[prev_word[j]].push_back(curr_word[j]);

                    if (indegrees.count(prev_word[j]) == 0)
                        indegrees[prev_word[j]] = 0;

                    indegrees[curr_word[j]]++;
                    break;
                }
                if (j == len - 1 && len < prev_word.size())
                    return false;
            }
        }
        // Topological sort
        queue<char> q;
        for(auto it:indegrees) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        string res_order;
        while(!q.empty()) {
            char c = q.front();
            res_order += c;
            q.pop();
            vector<char> &adj_list = Graph[c];
            for(int i=0; i<adj_list.size(); i++) {
                indegrees[adj_list[i]]--;
                if (indegrees[adj_list[i]] == 0) {
                    q.push(adj_list[i]);
                }
            }
        }

        //cout << "order : " << res_order << "\n";
        int curr_index = 0;
        for(int i=0; i<order.size(); i++) {
            char c = order[i];
            if (indegrees.count(c) > 0) {
                if (curr_index >= res_order.size() || res_order[curr_index] != c)
                    return false;
                curr_index++;
            }
        }

        return true;
    }
};
*/

/*
Complexity Analysis

Time Complexity: O(C), where C is the total content of words.

Space Complexity: O(1).
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_map[26];
        for(int i=0; i<order.size(); i++) {
            order_map[order[i] - 'a'] = i;
        }

        for(int i=0; i<words.size()-1; i++) {
            string &word1 = words[i];
            string &word2 = words[i+1];
            int len = min(word1.size(), word2.size());
            for(int k=0; k<len; k++) {
                if (word1[k] != word2[k]) {
                    if (order_map[word1[k]-'a'] > order_map[word2[k]-'a'])
                        return false;
                    break;
                }
                if (k == len - 1 && len < word1.size())
                    return false;
            }
        }
        return true;
    }
};
