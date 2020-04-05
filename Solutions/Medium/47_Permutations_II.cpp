/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

class Solution {
public:
    void permuations(vector<int>& nums, vector<int> &current) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            // We calculated permutation with same value
            if (i > 0 && nums[i] == nums[i-1] && visited[i-1] == false)
                continue;

            if (visited[i] == false) {
                visited[i] = true;
                current.push_back(nums[i]);
                permuations(nums,current);
                visited[i] = false;
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        vector<int> current;
	// Sort array first to eliminate duplicate results
        sort(nums.begin(), nums.end());
        permuations(nums,current);
        return result;
    }
private:
    vector<bool> visited;
    vector<vector<int>> result;
};
