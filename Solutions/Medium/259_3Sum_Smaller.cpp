/*
 Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?
 */

//Time : O(N^2)
//Space: O(1)
//
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int result = 0;
        for(int i=0; i<nums.size();i++) {
            int l = i+1;
            int r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    result += (r - l);
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};
