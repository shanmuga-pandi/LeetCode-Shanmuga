/*
 Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int end = 0;
        int start = 0;
        int result = 0;
        int n = A.size();
        int K = 1;
        while(end < n) {
            if (A[end] == 0)
                K--;
            end++;
            while(K < 0) {
                if (A[start] == 0)
                    K++;
                start++;
            }
            result = max(result, end - start);
        }
        return result;
    }
};
