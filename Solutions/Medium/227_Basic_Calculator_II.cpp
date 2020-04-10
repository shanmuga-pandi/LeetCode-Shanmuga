/*
 Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
 */

class Solution {
public:
    int calculate(string s) {
        char sign = '+';
        long int result = 0;
        istringstream istr(s);
        int num;
        stack<long int> stk;
        while(istr >> num) { // Read number
            if (sign == '+' || sign == '-') {
                stk.push( sign == '+' ? num : -num);
            } else {
                int temp = stk.top();
                if (sign == '*') {
                    temp *= num;
                } else {
                    if (num) // avoid division by 0
                        temp /= num ;
                    else
                        temp = 0;
                }
                stk.pop();
                stk.push(temp);
            }
            istr >> sign; // Read sign
        }
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
