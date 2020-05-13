/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    string removeKdigits(string num, int k) {
        list<char> stk;
        for(char c: num) {
            while(!stk.empty() && k > 0 && stk.back() > c) {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        while(!stk.empty() && k > 0) {
            stk.pop_back();
            k--;
        }
        string result;
        bool leadingZero = true;
        char c;
        while(!stk.empty()) {
            c = stk.front();
            stk.pop_front();
            if (c == '0' && leadingZero)
                continue;
            leadingZero = false;
            result += c;
        }
        if (result == "")
            return "0";

        return result;
    }
};
