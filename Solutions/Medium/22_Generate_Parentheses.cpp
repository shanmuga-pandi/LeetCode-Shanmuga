/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 

//Time : Time Complexity : O(\dfrac{4^n}{\sqrt{n}})O(n). Each valid sequence has at most n steps during the backtracking procedure.

Space Complexity : O(\dfrac{4^n}{\sqrt{n}})O(n), as described above, and using O(n)O(n) space to store the sequence.
*/

class Solution {
public:

    void generateParenthesis(int open, int close, string s, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if (close < open)
            return;

        if (open > 0) {
            generateParenthesis(open-1,close, s+'(', res);
        }
        if (close > 0) {
             generateParenthesis(open,close-1, s+')', res);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n,n,string(),res);
        return res;
    }
};
