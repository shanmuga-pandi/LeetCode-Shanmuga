/*
 You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
 */

// Time : O(log n)
// Space : O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        if (nums.size() == 0)
            return 0;
        if (lo == hi)
            return nums[lo];

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool isHalvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid] == nums[mid-1]) {
                if (isHalvesAreEven)
                    hi = mid-2;
                else
                    lo = mid+1;
            } else if (nums[mid] == nums[mid+1]) {
                if (isHalvesAreEven)
                    lo = mid+2;
                else
                    hi = mid-1;
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};
