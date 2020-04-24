/*
 Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
 */

// Time : O(N)
// Space : O(1) 

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0, result = 0, count = 0;
        unordered_map<char, int> hash_map;
        int n = s.size();
        while(end < n) {
            hash_map[s[end]]++;
            if (hash_map[s[end]] == 1) // new char found
                count++;
            end++;

            while(count > 2) {
                hash_map[s[start]]--;
                if(hash_map[s[start]] == 0) //one char removed
                    count--;
                start++;
            }

            result = max(result, end - start);
        }
        return result;
    }
};
