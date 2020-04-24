/*
 Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
 */

// Time : O(N)
// Space : O(K)

class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>& A, int K) {
        int start = 0;
        int end = 0;
        int count = 0;
        unordered_map<int,int> hash_map;
        int result = 0;
        int n = A.size();
        while(end < n) {
            hash_map[A[end]]++;
            if (hash_map[A[end]] == 1) // Found new char
                count++;

              while(count > K) {
                  hash_map[A[start]]--;
                  if (hash_map[A[start]] == 0) // removed a char
                      count--;
                  start++;
              }

            end++;
            result += end - start;
        }
        //cout << result << " ";
        return result;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
         // exactly(K) = atMost(K) - atMost(K-1)
	 return subarraysWithAtMostKDistinct(A,K) - subarraysWithAtMostKDistinct(A,K-1);
    }

};
