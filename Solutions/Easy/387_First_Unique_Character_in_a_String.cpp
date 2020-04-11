/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for(char c: s) {
            count[c]++;
        }
        int i = 0;
        for(char c:s) {
            if (count[c] == 1)
                return i;
            i++;
        }
        return -1;
    }
};
