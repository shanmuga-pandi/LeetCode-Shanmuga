/*
 Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
 */

// Time : O(n log n)
// Space : O(n)

class Solution {
public:
    #define iterator vector<int>::iterator

    int sort_count(iterator l, iterator r) {
        if (r - l <= 1)
            return 0;

        iterator mid = l + (r-l) / 2;
        int count = sort_count(l, mid) + sort_count(mid, r);
        for(iterator i=l, j=mid; i<mid; i++) {
            while(j < r && *i > 2L * *j)
                j++;
            count += j - mid;
        }
        inplace_merge(l,mid,r);
        return count;
    }


    int reversePairs(vector<int>& nums) {
        return sort_count(nums.begin(), nums.end());
    }
};
