/*
 Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
 */

// Time : O(M*N)
// Space : O(1)

class Solution {
public:
    string minWindow(string S, string T) {
        int sIndex = 0;
        int tIndex = 0;
        int result_index;
        int result_size = INT_MAX;
        while(sIndex < S.size()) {
            if (S[sIndex] == T[tIndex]) {
                tIndex++;

                if (tIndex == T.size()) {
                    // We find the substring, but it may not minimum one
                    int end = sIndex;
                    tIndex--; // Move to last char
                    // Move backwards to find the minimum length
                    while(tIndex >= 0) {
                        if (S[sIndex] == T[tIndex]) {
                            tIndex--;
                        }
                        sIndex--;
                    }
                    sIndex++;
                    tIndex = 0; // Set back to beginning
                    int size = end - sIndex + 1;
                    if (result_size > size) {
                        result_size = size;
                        result_index = sIndex;
                    }
                }
            }
            sIndex++;
        }
        return result_size == INT_MAX ? "" : S.substr(result_index, result_size);
    }
};
