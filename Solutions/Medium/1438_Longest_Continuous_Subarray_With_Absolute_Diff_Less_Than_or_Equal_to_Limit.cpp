/*
 Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
 */

// Time : O(N log N)
// Space: O(N)
class Solution_multi_set {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> sub_arr;
        int result = 0;
        int i = 0;
        for(int num : nums) {
            sub_arr.insert(num);
            if (*sub_arr.rbegin() - *sub_arr.begin() > limit) {
                sub_arr.erase(sub_arr.find(nums[i]));
                i++;
            }
            result = max(result, (int) sub_arr.size());
        }
        return result;
    }
};


// Time : O(N)
// Space: O(N)
// Deque
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min_q;
        deque<int> max_q;
        int result = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            while(!min_q.empty() && min_q.back() > nums[j]) {
                min_q.pop_back();
            }
            while(!max_q.empty() && max_q.back() < nums[j]) {
                max_q.pop_back();
            }
            min_q.push_back(nums[j]);
            max_q.push_back(nums[j]);
            if (max_q.front() - min_q.front() > limit) {
                if (min_q.front() == nums[i]) 
                    min_q.pop_front();
                if (max_q.front() == nums[i]) 
                    max_q.pop_front();
                i++;
            }
            result = max(result, j-i+1);
        }
        return result;
    }
};
