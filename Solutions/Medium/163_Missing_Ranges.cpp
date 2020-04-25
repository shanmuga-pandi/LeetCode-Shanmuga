/*
 Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
 */

// Time : O(N)
// Space : O(1)
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, long int lower, int upper) {
        vector<string> result;
        for(int num:nums) {
            if (num > lower) {
                string s = to_string(lower) + ((lower != num - 1) ? ("->" + to_string(num - 1)) : "");
                result.push_back(s);
            }
            lower = num+1l;
        }
        if (lower <= upper) {
            string s = to_string(lower) + ((lower != upper) ? ("->" + to_string(upper)) : "");
            result.push_back(s);
        }
        return result;
    }
};
