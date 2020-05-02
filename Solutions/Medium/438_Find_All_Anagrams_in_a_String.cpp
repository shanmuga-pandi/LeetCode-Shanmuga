/*
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

// Time : O(M+N)
// Space : O(max(m,n))

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash_map;
        int count = 0;
        for(char c:p) {
            hash_map[c]++;
            count++;
        }
        int start = 0;
        int end = 0;
        int n = s.size();
        vector<int> result;
        while(end < n) {
            hash_map[s[end]]--;
            if (hash_map[s[end]] >= 0)
                count--;
            end++;
            while(count == 0) {
                if (end - start == p.size())
                    result.push_back(start);
                hash_map[s[start]]++;
                if (hash_map[s[start]] > 0)
                    count++;
                start++;
            }
        }
        return result;
    }
};
