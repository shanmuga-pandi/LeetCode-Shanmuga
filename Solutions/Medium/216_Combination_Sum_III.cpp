/*
 Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        combinationSum(1, n, k, path);
        return result;
    }
private:
    void combinationSum(int index, int target, int k, vector<int> &path) {
        if (target == 0) {
            if (path.size() == k)
                result.push_back(path);
            return;
        }
        if (target <= 0 || index == 10 || path.size() == k)
            return;

        path.push_back(index);
        combinationSum(index+1, target-index, k, path);
        path.pop_back();
        combinationSum(index+1, target, k, path);

    }
    vector<vector<int>>result;
};
