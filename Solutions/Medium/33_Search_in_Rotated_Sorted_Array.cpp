/*
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */

// Time : O(log n)
// Space : O(1)
//
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        //cout << l << " " << r << "\n";
        while(l<=r) {
            int mid = l + (r -l) / 2;
            if (nums[mid] == target)
                return mid;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        if (nums.size() == 0)
            return -1;
        // Find the rotation point
        int p = l;
        while(l<r) {
            int mid = l + (r -l) / 2;
            if (nums[l] <= nums[mid] && nums[r] >= nums[mid]) {
                p = l;
                break;
            }
            p = r;
            if (nums[mid] > nums[l]) {
               l = mid+1;
            } else {
                r = mid;
            }
        }
        
        l = 0;
        r = nums.size()-1;
        //cout << p << "\n";
        if (p == 0) {
            return binarySearch(nums,target, l, r);
        } else {
            if (target >= nums[p] && target <= nums[r])
                return binarySearch(nums,target, p, r);
            else
                return binarySearch(nums,target, l, p-1);
        }
        
        return -1;
    }
};
