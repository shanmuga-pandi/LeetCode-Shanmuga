/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    Solution() {
        memo[1] = {"0", "1", "8"};
        rotate_map["0"] = "0";
        rotate_map["1"] = "1";
        rotate_map["6"] = "9";
        rotate_map["8"] = "8";
        rotate_map["9"] = "6";
    }
    vector<string> construct(int n, int level) {
        if (n == 0)
            return {""};

        if (memo.count(n) > 0)
            return memo[n];

        vector<string> result;
        for(auto it: rotate_map) {
            if (level == 1 && it.first == "0")
                continue;
            vector<string> sub_list = construct(n-2, level+1);
            for(string s:sub_list)
                result.push_back(it.second + s + rotate_map[it.second]);
        }

        memo[n] = result;
        return result;

    }
    vector<string> findStrobogrammatic(int n) {
        return construct(n, 1);
    }
private:
    unordered_map<int, vector<string>> memo;
    unordered_map<string,string> rotate_map;
};
