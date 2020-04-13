/*
 Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

// Time : O(N^2)
// Space : O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        long int result = 0;
        long int prevClose = LONG_MAX;
        for(int i=0; i<nums.size();i++) {
            int l = i+1;
            int r = nums.size() - 1;
            while(l < r) {
                long int sum = nums[i] + nums[l] + nums[r];
                long int diff = abs(target - sum);
                if (prevClose > diff) {
                    result = sum;
                    prevClose = diff;
                }
                if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};
