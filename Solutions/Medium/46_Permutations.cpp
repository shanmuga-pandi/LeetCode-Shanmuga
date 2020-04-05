/*
 Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
            if (visited[i] == false) {
                visited[i] = true;
                current.push_back(nums[i]);
                permuations(nums,current);
                visited[i] = false;
                current.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        vector<int> current;
        permuations(nums,current);
        return result;
    }
private:
    vector<bool> visited;
    vector<vector<int>> result;
};



class Solution {
public:
    void permuations(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++) {
            swap(nums[i], nums[index]);
            permuations(nums, index+1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        permuations(nums, 0);
        return result;
    }
private:

    vector<vector<int>> result;
};
