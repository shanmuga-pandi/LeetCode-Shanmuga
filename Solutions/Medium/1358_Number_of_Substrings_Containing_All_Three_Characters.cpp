/*
 Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 3;
        unordered_map<char,int> hash_map;
        int end = 0;
        int start = 0;
        int result = 0;
        int n = s.size();
        int finds = 0;
        while(end < n) {
            hash_map[s[end]]++;
            if (hash_map[s[end]] == 1)
                count--;
            end++;
            while(count == 0) {
                hash_map[s[start]]--;
                if (hash_map[s[start]] == 0)
                    count++;
                start++;
                finds++;
            }
            //result += start; // This also works fine
            result += finds; // This also works fine
	    // Like a coin change calculation, we do get add prev possible ways + new possible ways
        }
        return result;
    }
};
