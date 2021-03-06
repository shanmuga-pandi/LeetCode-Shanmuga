/*
 There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Example:

Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

            post1  post2  post3      
 -----      -----  -----  -----       
   1         c1     c1     c2 
   2         c1     c2     c1 
   3         c1     c2     c2 
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1
 */

// Time : O(N)
// Space: O(N)

class Solution {
public:
    int numWays(int n, int k) {
        // if no house to paint, return 0
        if (n == 0)
            return 0;
        // If we have one house, we can paint with k options
        if (n == 1)
            return k;

        // Each house having k options to paint
        if (n == 2)
            return k*k;

        int dp[n+1];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;

        for(int i=3; i<=n; i++) {
            // Color the ith house different from i-1 house +
            // Color ith house same as i-2 house
            dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
        }
        return dp[n];
    }
};
