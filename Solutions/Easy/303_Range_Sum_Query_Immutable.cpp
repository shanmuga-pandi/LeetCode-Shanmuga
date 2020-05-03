/*
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 */
// Time : O(N) for insert, O(1) for query
// space : O(N)

class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix_sum = vector<int>(nums.size()+1);
        for(int i=0;i<nums.size();i++) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        i++;
        j++;
        return prefix_sum[j] - prefix_sum[i-1];
    }
private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
