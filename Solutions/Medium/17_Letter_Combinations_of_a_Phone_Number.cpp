/*
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

/*
 * Time complexity : O(3^N * 4^M) where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.

Space complexity : O(3^N * 4^M) since one has to keep 3^N * 4^M solutions.
 */


// Recursion
class Solution {
public:
    vector<string> letterCombinations(string &digits, int n, unordered_map<char, string> &mapping, unordered_map<int, vector<string>> &memo) {
        if (n == 0)
            return {""};

        if (memo.count(n) > 0) {
            return memo[n];
        }

        string &chars = mapping[digits[n-1]];
        vector<string> res;
        vector<string> getNextList = letterCombinations(digits, n-1, mapping, memo);
        for(char c:chars) {
            for(string &str : getNextList) {
                res.push_back(str + c);
            }
        }
        memo[n] = res;
        return memo[n];
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        unordered_map<int, vector<string>> memo;
        unordered_map<char, string> mapping;
        mapping.emplace('2', "abc");
        mapping.emplace('3', "def");
        mapping.emplace('4', "ghi");
        mapping.emplace('5', "jkl");
        mapping.emplace('6', "mno");
        mapping.emplace('7', "pqrs");
        mapping.emplace('8', "tuv");
        mapping.emplace('9', "wxyz");
        return letterCombinations(digits, digits.size(), mapping, memo);
    }
};


// Iterative

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        unordered_map<char, string> mapping;
        mapping.emplace('2', "abc");
        mapping.emplace('3', "def");
        mapping.emplace('4', "ghi");
        mapping.emplace('5', "jkl");
        mapping.emplace('6', "mno");
        mapping.emplace('7', "pqrs");
        mapping.emplace('8', "tuv");
        mapping.emplace('9', "wxyz");

        vector<string> result = {""};
        for(int i=0; i<digits.size(); i++) {
            string &chars = mapping[digits[i]];
            vector<string> res;
            for(char c:chars) {
                for(string &str : result) {
                    res.push_back(str + c);
                }
            }
            result = res;
        }
        return result;
    }
};
