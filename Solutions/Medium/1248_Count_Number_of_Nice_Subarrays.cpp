/*
 Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int odds = 0;
        int result = 0;
        while(end < n) {
            if (nums[end] % 2 == 1) {
                odds++;
            }
            end++;
            while(odds > k) {
                if (nums[start] % 2 == 1) {
                    odds--;
                }
                start++;
            }
            result += end - start;
        }
        return result;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums,k) - atMostK(nums, k-1);
    }
};
