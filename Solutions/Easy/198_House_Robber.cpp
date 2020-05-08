/*
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 */

// Memoization
// Time : O(N)
// Space: O(N)
namespace Top_down {
class Solution {
public:
    int maxGain(vector<int>& nums, int N, vector<int> &memo) {
        if (N <= 0)
            return 0;
        if (memo[N] != -1)
            return memo[N];

        return memo[N] = max(nums[N-1] + maxGain(nums, N-2, memo) , maxGain(nums, N-1, memo));
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 1, -1);
        return maxGain(nums, nums.size(), memo);
    }
};
}

// DP
// Time : O(N)
// Space : O(N)
class Solution_DP {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2; i<=n;i++) {
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};

// DP - Space optimized
// Time : O(N)
// Space : O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1);
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = nums[0];
        for(int i=2; i<=n;i++) {
            curr = max(nums[i-1] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
