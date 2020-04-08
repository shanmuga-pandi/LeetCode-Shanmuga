/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        string result;
        int i=0;
        int j=0;
        int r_index;
        int r_size = INT_MAX;
        unordered_map<char, int> t_map;
        for(char c:t) {
            t_map[c]++;
        }

        unordered_set<char> common_char;
        unordered_map<char, int> s_map;
        while(j < s.size()) {
            while(i < s.size() && t_map.count(s[i]) == 0) {
                i++;
                j = (j < i) ? i : j;
            }

            if (t_map.count(s[j]) > 0) {
                s_map[s[j]]++;
                if(s_map[s[j]] >= t_map[s[j]]) {
                    common_char.emplace(s[j]);
                }
            }

            if (common_char.size() == t_map.size()) {
                int size = j - i + 1;
                if (size < r_size) {
                    r_index = i;
                    r_size = size;
                    if (r_size == t.size()) {
                        //cout << "it braek";
                        break;
                    }
                }
                s_map[s[i]]--;
                s_map[s[j]]--;
                if (s_map[s[i]] < t_map[s[i]])
                    common_char.erase(s[i]);
                if (s_map[s[j]] < t_map[s[j]])
                    common_char.erase(s[j]);
                i++;
            }
            else {
                j++;
            }
        }

        if (r_size == INT_MAX)
            return "";

        return s.substr(r_index, r_size);
    }
};
