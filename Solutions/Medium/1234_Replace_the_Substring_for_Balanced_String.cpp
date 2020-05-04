/*
 You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.

 

Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 
Example 4:

Input: s = "QQQQ"
Output: 3
Explanation: We can replace the last 3 'Q' to make s = "QWER".
 

Constraints:

1 <= s.length <= 10^5
s.length is a multiple of 4
s contains only 'Q', 'W', 'E' and 'R'.
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> hash_map;
        int k = s.size() / 4;
        for(char c: s) {
            hash_map[c]++;
        }
        int min_len = INT_MAX;
        int end = 0;
        int start = 0;
        int n = s.size();
        while(end < n) {
            hash_map[s[end]]--;
            end++;
            while(start < n && hash_map['Q'] <= k && hash_map['W'] <= k && hash_map['E'] <= k && hash_map['R'] <= k) {
                min_len = min(min_len, end - start);
                hash_map[s[start]]++;
                start++;
            }
        }
        return min_len;
    }
};
