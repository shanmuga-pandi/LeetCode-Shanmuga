/*
 Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int> dq;
        int n = A.size();
        if (n == 0)
            return -1;
        vector<int> prefix_sum(n,0);
        prefix_sum[0] = A[0];
        for(int i=1; i<n;i++) {
            prefix_sum[i] = A[i] + prefix_sum[i-1];
        }
        int end = 0;
        int result = INT_MAX;
        while(end < n) {
            if (prefix_sum[end] >= K)
                result = min(result, end+1);

             while(!dq.empty() && prefix_sum[dq.back()] > prefix_sum[end]) {
              dq.pop_back();
            }

            while(!dq.empty() && prefix_sum[end] - prefix_sum[dq.front()] >= K) {
                result = min(result, end - dq.front());
                dq.pop_front();
            }

            dq.push_back(end);
            end++;
        }
        return result == INT_MAX ? -1 : result;
    }
};
