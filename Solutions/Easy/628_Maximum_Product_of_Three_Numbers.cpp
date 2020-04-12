/*
 Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */

// Time : O(N)
// Space : O(1)
class Solution {
public:
    void updateThreeMax(int maxArr[3], int num) {
        if (num >= maxArr[0]) {
            maxArr[2] = maxArr[1];
            maxArr[1] = maxArr[0];
            maxArr[0] = num;
            return;
        }
        if (num >= maxArr[1]) {
            maxArr[2] = maxArr[1];
            maxArr[1] = num;
            return;
        }
        
        if (num >= maxArr[2])
             maxArr[2] = num;
    }
    void updateThreeMin(int minArr[3], int num) {
        if (num <= minArr[0]) {
            minArr[2] = minArr[1];
            minArr[1] = minArr[0];
            minArr[0] = num;
            return;
        }
        if (num <= minArr[1]) {
            minArr[2] = minArr[1];
            minArr[1] = num;
            return;
        }
        
        if (num <= minArr[2])
             minArr[2] = num;
    }
    
    int maximumProduct(vector<int>& nums) {
        int maxArr[3] = {INT_MIN};
        int minArr[3] = {INT_MAX};
        for(int i=0; i<nums.size();i++) {
            updateThreeMax(maxArr, nums[i]);           
            updateThreeMin(minArr, nums[i]); 
        }
        
       return max(maxArr[0] * maxArr[1] * maxArr[2] ,
                 minArr[0] * minArr[1] * maxArr[0]);
    }
};
