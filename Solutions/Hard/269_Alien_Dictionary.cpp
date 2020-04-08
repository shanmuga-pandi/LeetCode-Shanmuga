/*
 There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
 */

class Solution {
public:
    string alienOrder(vector<string>& words) {

        // Each character's indegree
        unordered_map<char, int> indegree;
        // Each character's adj list
        unordered_map<char, unordered_set<char>> graph;

        //Set all character's indegree as 0.
        for(string& word: words) {
            for(char c: word) {
                indegree[c] = 0;
            }
        }

        for(int i=0; i<words.size()-1; i++) {
            string &curr = words[i];
            string &next = words[i+1];
            int len = min(curr.size(), next.size());

            //Check for the first difference of chars and add that as adj list

            for(int j=0; j<len; j++) {
                if (curr[j] != next[j]) {
                    // Check whether we already has edge or not
                    // If not add the edge and increase indegree by 1
                    if (graph[curr[j]].count(next[j]) == 0) {
                        graph[curr[j]].emplace(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }

                // Check if first word is more than next word and no difference char found. It is like curr is starts with next
                if (j == len - 1 and curr.size() > next.size()) return "";
            }
        }

        //Topological Sort.
        // Add char to queue only if it's indegree is 0(That means no dependency now)
        queue<char> q;
        string result;
        for(auto& deg : indegree) {
            if (deg.second == 0)
                q.push(deg.first);
        }
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            unordered_set<char> &adj_list = graph[c];
            for(char v: adj_list) {
                indegree[v]--;
                // If indegree[v] is 0 means, then there is no more dependenncy for v.
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
            cout << result;
       return result.size() == indegree.size() ? result : "";
    }
};

