/*
 In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int atMostKSum(vector<int>& A, int S) {
        if (S < 0)
            return 0;

        int end = 0;
        int start = 0;
        int n = A.size();
        int result = 0;
        int sum = 0;
        while(end < n) {
            sum += A[end];
            end++;
            while(sum > S) {
                sum -= A[start];
                start++;
            }
            result += end - start;
        }
        return result;
    }
    int numSubarraysWithSum(vector<int>& A, int S) {
        // Solution 1 : With hash_map
        /*unordered_map<int, int> hash_map;
        hash_map[0] = 1;
        int sum = 0;
        int result = 0;
        for(int num: A) {
            sum += num;
            result += hash_map[sum-S];
            hash_map[sum]++;
        }
        return result;*/

        return atMostKSum(A, S) - atMostKSum(A, S-1);
    }
};
