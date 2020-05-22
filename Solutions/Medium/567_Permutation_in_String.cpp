/*
 Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
 */

//Time : O(M+N)
//Space : O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> char_map(26, 0);
        int count = s1.size();
        for(char c:s1) {
            char_map[c-'a']++;
        }
        int start = 0;
        int end = 0;
        int N = s2.size();
        while(end < N) {
            char_map[s2[end]-'a']--;
            if (char_map[s2[end]-'a'] >= 0)
                count--;
            end++;
            while(count == 0) {
                if (end - start == s1.size())
                    return true;
                char_map[s2[start]-'a']++;
                if (char_map[s2[start]-'a'] > 0)
                    count++;
                start++;
            }
        }
        return false;
    }
};
