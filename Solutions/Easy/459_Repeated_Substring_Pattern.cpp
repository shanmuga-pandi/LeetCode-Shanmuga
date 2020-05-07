/*
 Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    /*bool checkValid(string &s, int n, int cuts) {
        if (n % cuts != 0)
            return false;
        string prev = s.substr(0, cuts);
        for(int i=cuts; i<n; i+=cuts) {
            if (prev != s.substr(i, cuts))
                return false;
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1; i<=n/2; i++) {
            if (checkValid(s, n, i))
                return true;
        }
        return false;
    } */

    bool repeatedSubstringPattern(string s) {
        // 1. Append same string
        // 2. Remove first and last character
        // 3. check for the string s in it
        // 4. If it presents, return true , else false
        return (s + s).substr(1).substr(0, s.size()*2 - 2).find(s) != -1;
    }
};
