/*
 Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
 */

// Time : O(n log n)
// Space : O(n)

// https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem

class Solution {
public:
    int sort_count(vector<long>& sums, int l, int r, int lower, int upper) {
        if (r - l <= 1)
            return 0;
        int mid = l + (r - l) / 2;
        int count = sort_count(sums, l, mid, lower, upper) +
            sort_count(sums, mid, r, lower, upper);
        int j1 = mid;
        int j2 = mid;
        for(int i=l; i<mid;i++) {
            while(j1 < r && sums[j1] - sums[i] < lower)
                j1++;
            while(j2 < r && sums[j2] - sums[i] <= upper)
                j2++;
            count += j2 - j1;
        }
        inplace_merge(sums.begin()+l, sums.begin()+mid, sums.begin()+r);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix_sum(n+1, 0);
        for(int i=0; i<n;i++) {
            prefix_sum[i+1] = nums[i] + prefix_sum[i];
        }
        return sort_count(prefix_sum, 0, n+1, lower, upper);
    }
};
