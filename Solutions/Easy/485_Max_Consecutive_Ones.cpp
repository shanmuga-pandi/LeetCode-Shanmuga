/*
 Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int end = 0;
        int start = 0;
        int n = nums.size();
        int result = 0;
        while(end < n) {
            if (nums[end] == 0) {
                end++;
                start = end;
                continue;
            }
            end++;
            result = max(result, end-start);
        }
        return result;
    }
};
