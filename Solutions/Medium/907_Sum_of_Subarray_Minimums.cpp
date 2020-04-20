/*
 Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
 */

// reference : https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C%2B%2BJavaPython-Stack-Solution

// Time : O(N)
// Space : O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return 0;

        // Length of strict bigger numbers on the left
        vector<int> left(n);
        // Length of strict bigger numbers on the right
        vector<int> right(n);

        stack<pair<int,int>> leftStack;
        for(int i=0; i<n;i++) {
            int count = 1;
            while(!leftStack.empty() && A[i] <= A[leftStack.top().first]) {
                count += leftStack.top().second;
                leftStack.pop();
            }
            leftStack.push({i, count});
            left[i] = count;
        }

        stack<pair<int,int>> rightStack;
        for(int i=n-1; i>=0;i--) {
            int count = 1;
            while(!rightStack.empty() && A[i] < A[rightStack.top().first]) {
                count += rightStack.top().second;
                rightStack.pop();
            }
            rightStack.push({i, count});
            right[i] = count;
        }

        int mod = 1e9 + 7;
        int result = 0;
        for(int i=0; i<n;i++) {
            result = ( result + (A[i] * left[i] * right[i]) ) % mod;
        }
        return result;
    }
};
