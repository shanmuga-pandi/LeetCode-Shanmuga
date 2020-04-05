/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;
        int count = -1;
        int sum = 0;
        bool isOdd = (m+n) % 2;
        int median_index = (m + n) / 2;
        if (!isOdd)
            median_index--;

        bool isMedianFound = false;
        int lastVal;
        while(i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                lastVal = nums1[i];
                i++;
            } else {
                lastVal = nums2[j];
                j++;
            }
            count++;
            if (count >= median_index) {
                sum += lastVal;
                if (isMedianFound) {
                    return sum/2.0f;
                }
                isMedianFound = true;
                if (isOdd)
                    return sum;
            }
        }

        int remaining = i < m ? i : j;
        vector<int>& arr = i < m ? nums1 : nums2;
        int size = i < m ? m : n;

        //cout << remaining << " " << isMedianFound;
        while(remaining < size) {
            lastVal = arr[remaining];
             remaining++;
             count++;
            if (count >= median_index) {
                sum += lastVal;
                //cout << " sum " << sum;
                if (isMedianFound) {
                    return sum/2.0f;
                }
                isMedianFound = true;
                if (isOdd)
                    return sum;
            }
        }

        return 0;
    }
};
