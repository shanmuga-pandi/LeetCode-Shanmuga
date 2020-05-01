/*
 Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
 */

// Time : log(m) M is sum of numbers
// Space : O(1)
//
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0 || m == 0)
            return 0;
        
        long int l=0, r=0;
        
        for(long int i: nums) {
            r+=i;
            l = max(l, i);
        }
        
        long int ans = LONG_MAX;
        while(l <= r) {
            long int mid = (l + r) / 2;
            int cuts = 1;
            long int sum = 0;
            for(int i:nums) {
                if (sum + i <= mid) {
                    sum = sum+i;
                } else {
                    cuts++;
                    sum = i;
                }
               // if (cuts > m)
                 //  break;
            }
            
            if ( cuts <= m) {
                r = mid - 1;
                ans = min(ans, mid);
            } else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
