/*
 Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
 */

class Solution {
    public:
        int calculate(string s) {
            stack<int> nums;
            stack<int> signs;
            int num = 0;
            int sign = 1;
            int result = 0;
            for(char c: s) {
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                } else if (c == '+') {
                    result += (sign * num);
                    sign = 1;
                    num = 0;
                } else if (c == '-') {
                    result += (sign * num);
                    sign = -1;
                    num = 0;
                } else if (c == '(') {
                    nums.push(result);
                    result = 0;
                    signs.push(sign);
                    sign = 1;
                } else if (c == ')') {
                    result += (sign * num);
                    num = 0;
                    sign = 1;
                    result = signs.top() * result + nums.top();
                    signs.pop();
                    nums.pop();
                }
            }

            result += (sign * num);
            return result;
        }
};
