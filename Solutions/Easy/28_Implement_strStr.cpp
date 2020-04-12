/*
 Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

// Time : O((N−L)L) in the worst case of numerous almost complete false matches, and O(N) in the best case of one single match
// Space: O(1)
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if (needleSize > haystackSize)
            return -1;
        if (needleSize == 0)
            return 0;
        while(i<haystackSize) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j=0;
            }
            if(j == needleSize)
                return i - needleSize;
        }
        return -1;
    }
};


