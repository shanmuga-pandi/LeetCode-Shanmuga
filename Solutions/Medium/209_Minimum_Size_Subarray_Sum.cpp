/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
 */

// Time : O(N)
// Space : O(1)
//
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0; 
        int j=0;
        int sum = 0;
        int result = INT_MAX;
        while(j < nums.size()) {
            sum += nums[j];
            while (sum >= s) {
                result = min(result, j-i+1);
                sum -= nums[i];
                i++; 
            }
            j++;
            
        }
        if (result == INT_MAX)
            return 0;
        
        return result;
    }
};
