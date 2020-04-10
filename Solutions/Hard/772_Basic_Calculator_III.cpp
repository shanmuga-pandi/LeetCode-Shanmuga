/*
 Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 */

class Solution {
private:
    void updateStack(char prevSign, long int num) {
              if (prevSign == '+') {
                  nums.push(num);
              } else if (prevSign == '-') {
                  nums.push(-num);
              } else if (prevSign == '*') {
                  int temp = nums.top();
                  nums.pop();
                  temp = temp * num;
                  nums.push(temp);
              } else if (prevSign == '/') {
                  int temp = nums.top();
                  nums.pop();
                  temp = num ? (temp / num) : 0;
                  nums.push(temp);
              }
    }
    stack<long int> nums;
    stack<char> signs;
public:
    int calculate(string s) {
        char prevSign = '+';
        long int num = 0;
        long int result = 0;
        int n = s.size();
        for(int i=0; i<n;i++) {
          char c = s[i];
          if (isdigit(c)) {
              num = num * 10 + (c - '0');
          } else if (c == '(') {
              nums.push(LONG_MAX);
              signs.push(prevSign);
              prevSign = '+';
          } else if (c == ')') {
              updateStack(prevSign, num);
              int temp = 0;
              while(nums.top() != LONG_MAX) {
                  temp += nums.top();
                  nums.pop();
              }
              nums.pop();
              //nums.push(temp);
              num = temp;
              prevSign = signs.top();
              signs.pop();
          } else {
              if (c == ' ')
                  continue;
              updateStack(prevSign, num);
              num = 0;
              prevSign = c;
          }
        }

        updateStack(prevSign, num);

        while(!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
