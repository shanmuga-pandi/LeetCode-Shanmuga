/*
 Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
 */


//Time : O(log(n))
//Space: O(1)

class Solution {
public:
    int mySqrt(int x) {

        // Find sqrt : Binary Search
        long int l = 1;
        long int r = x/2;
        while(l <= r) {
            long int mid = (l + r) / 2;
            if (mid * mid == x)
                return mid;

            if (mid * mid < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l-1;
    }
};
