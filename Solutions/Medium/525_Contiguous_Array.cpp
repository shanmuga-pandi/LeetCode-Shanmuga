/*
 Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
 */

// Time : o(N)
// Space : O(N)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count_map;
        int count = 0;
        count_map[0] = -1;
        int result = 0;
        for(int i=0; i<nums.size();i++) {
            if (nums[i] == 0)
                count--;
            else
                count++;
            if (count_map.count(count) > 0) {
                result = max(result, i - count_map[count]);
            } else {
                count_map[count] = i;
            }
        }
        return result;
    }
};
