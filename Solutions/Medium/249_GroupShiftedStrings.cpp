/*
 *
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    string hashing(string s) {
      if (s.length() == 0)
          return s;

      int diff = 26 - (s[0] - 'a') ;
      string conv(s.length(), 0);
        int i = 0;
      for(char c:s) {
          conv[i++] = ((c - 'a' + diff) % 26) + 'a' ;
      }
        return conv;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> maps;
        for(string s:strings) {
            maps[hashing(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &lists: maps) {
            res.push_back(lists.second);
        }
        return res;
    }
};
