/*
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates, 0, target, path);
        vector<vector<int>>result = vector<vector<int>>(unique_set.begin(), unique_set.end());
        return result;
    }
private:
    void combinationSum(vector<int>& candidates, int index, int target, vector<int> &path) {
        if (target == 0) {
            unique_set.emplace(path);
            return;
        }
        if (target < 0 || index == candidates.size())
            return;

	// With taking the current candidate
        path.push_back(candidates[index]);
        combinationSum(candidates, index+1, target-candidates[index], path);
        path.pop_back();

	// without taking the current candidate
        combinationSum(candidates, index+1, target, path);

    }
    set<vector<int>> unique_set;
};
