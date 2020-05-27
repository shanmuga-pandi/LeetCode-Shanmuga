/*
 Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
 */

// Time : O(N^2)
// Space : O(N^2)

class Solution_memo {
public:
    int countSubstring(string &s, int start, int end, vector<vector<int>> &memo) {
        if (end <= start)
            return 1;
        if (memo[start][end] != -1)
            return memo[start][end];
        if (s[start] == s[end])
            return memo[start][end] = countSubstring(s, start+1, end-1, memo);

        return memo[start][end] = 0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        for(int i=0; i<n;i++) {
            for(int j=i; j<n;j++) {
                count += countSubstring(s,i,j,memo);
            }
        }
        return count;
    }
};

// Time : O(N^2)
// Space : O(1)
class Solution {
public:
    int extendPalindrome(string &s, int left, int right) {
        int count = 0;
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n;i++) {
            count += extendPalindrome(s, i,i); //odd length
            count += extendPalindrome(s, i, i+1); //even length
        }
        return count;
    }
};
