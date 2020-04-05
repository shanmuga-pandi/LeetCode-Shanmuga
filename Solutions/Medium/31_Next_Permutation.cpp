/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        // Find first decreasing value's position from end, Say i
        int N = nums.size();
        int prev = nums[N-1];
        int i = N-1;
        while( i>=0 && prev <= nums[i]) {
            prev = nums[i];
            i--;
        }
        // Find first bigger element than i, from end and swap
        if (i>=0) {
            int j = N-1;
            while(j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        // Reverse the all elements from i+1
        reverse(nums.begin() + i + 1, nums.end());
        return ;
    }
};
