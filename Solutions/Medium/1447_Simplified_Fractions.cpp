/*
 Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. The fractions can be in any order.

 

Example 1:

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
Example 2:

Input: n = 3
Output: ["1/2","1/3","2/3"]
Example 3:

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
Example 4:

Input: n = 1
Output: []
 

Constraints:

1 <= n <= 100
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for(int i=1; i<=n;i++) {
            for(int j=i+1; j<=n; j++) {
                if (j&1 || i&1 ) { //both are odd
                    if (gcd(i,j) == 1)
                        result.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return result;
    }
};
