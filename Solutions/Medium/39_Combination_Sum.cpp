/*
 Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        combinationSum(candidates, 0, target, path);
        return result;
    }
private:
    void combinationSum(vector<int>& candidates, int index, int target, vector<int> &path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0 || index == candidates.size())
            return;

        path.push_back(candidates[index]);
        combinationSum(candidates, index, target-candidates[index], path);
        path.pop_back();
        combinationSum(candidates, index+1, target, path);

    }
    vector<vector<int>>result;
};
