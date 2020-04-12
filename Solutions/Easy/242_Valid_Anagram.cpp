/*
 Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

// Time complexity O(m+n)
// Space complexity (a+b) // No of unique Chars in each string

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_count;
        unordered_map<char,int> t_count;
        if (s.size() != t.size())
            return false;
        for(char c : s) {
            s_count[c]++;
        }
        for(char c : t) {
            t_count[c]++;
        }
        if (s_count.size() != t_count.size())
            return false;
        for(auto it : s_count) {
            if (t_count[it.first] != it.second)
                return false;
        }
        return true;
    }
};
