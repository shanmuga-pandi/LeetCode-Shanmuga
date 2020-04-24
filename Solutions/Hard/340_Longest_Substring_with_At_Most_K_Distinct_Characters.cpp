/*
 Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
 */

// Time : O(N)
// Space : O(K) K unique chars
//
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0 || s.size() == 0)
            return 0;
        int start = 0, end = 0, result = 0, count = 0;
        unordered_map<char, int> hash_map;
        int n = s.size();
        while(end < n) {
            hash_map[s[end]]++;
            if (hash_map[s[end]] == 1) // new char found
                count++;
            end++;
            
            while(count > k) {
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
