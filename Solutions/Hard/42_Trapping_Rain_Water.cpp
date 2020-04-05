/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeightIndex = 0;
	// Find the Maximum height index
        for(int i=0; i<height.size();i++) {
            if (height[i] > height[maxHeightIndex]) {
                maxHeightIndex = i;
            }
        }
        int leftTallHeight = 0;
        int result = 0;
	// Flow the water from left to max Wall
        for(int i=0; i<maxHeightIndex;i++) {
            leftTallHeight = max(leftTallHeight, height[i]);
            result += leftTallHeight - height[i];
        }
        
        int rightTallHeight = 0;
	// Flow the water from right to max Wall.
        for(int i=height.size()- 1 ; i>maxHeightIndex;i--) {
            rightTallHeight = max(rightTallHeight, height[i]);
            result += rightTallHeight - height[i];
        }
        return result;
    }
};
