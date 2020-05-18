/*
 Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

 

Example 1:

Input: S = "0110", N = 3
Output: true
Example 2:

Input: S = "0110", N = 4
Output: false
 

Note:

1 <= S.length <= 1000
1 <= N <= 10^9
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1;i<=N;i++) {
            int n = i;
            string binaryN;
            while(n > 0) {
                int d = n & 1;
                n = n >> 1;
                binaryN = ((d == 0) ? "0" : "1" ) + binaryN;
            }
            if (S.find(binaryN) == -1)
                return false;
        }
        return true;
    }
};
