/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */
// Time : O(N)
// Space : O(N)

// Solution 1 : With Stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int result = 0;
        stk.push(-1);
        int n = s.size();
        for(int i=0; i<n;i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                result = max(result, i - stk.top());
            }
        }
        return result;
    }
};


// Time : O(N)
// Space : O(1)


lass Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int result = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                result = max(result, right * 2);
            }
            // Check for invalid case
            if (right > left) {
                right = 0;
                left = 0;
            }
        }

        left = 0;
        right = 0;
        for(int i=n-1; i>=0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                result = max(result, right * 2);
            }
            // Check for invalid case
            if (left > right) {
                right = 0;
                left = 0;
            }
        }
        return result;
    }
};
