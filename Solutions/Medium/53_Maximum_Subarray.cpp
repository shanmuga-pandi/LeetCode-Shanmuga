/*
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
      // Solution 1: 
        int n = nums.size();
        if (n == 0)
            return INT_MIN;
        int prev = nums[0];
        int res = prev;
        for(int i=1; i<n ;i++) {
            prev = max(nums[i] , prev + nums[i]);
            res = max(res, prev);                
        }
        return res;
        
      // Solution 2:
        if (nums.size() == 0) return INT_MIN;
         
         int result = INT_MIN;
         
         // Find max sum from left
         int sum = 0;
         for(int i=0; i<nums.size();i++) {
             sum = sum + nums[i];
             result = max(result, sum);
             if (sum < 0)
                 sum = 0;
             
         }
         
          // Find max sum from right
         sum = 0;
         for(int i=nums.size()-1; i>=0;i--) {
             sum = sum + nums[i];
             result = max(result, sum);
             if (sum < 0)
                 sum = 0;
         }
         
         return result;
    }
};
