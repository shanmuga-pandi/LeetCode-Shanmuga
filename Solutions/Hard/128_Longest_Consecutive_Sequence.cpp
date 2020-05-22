/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> hash_map;
        for(int num:nums) {
            if (hash_map[num] > 0)
                continue;
            int left = hash_map[num-1];
            int right = hash_map[num+1];
            int sum  = left+right+1;
            result = max(result, sum);

            hash_map[num] = sum;
            // Update left and right with latest sum
            if (left > 0)
            hash_map[num-left] = sum;
            if (right > 0)
            hash_map[num+right] = sum;
        }
        return result;
    }
};
