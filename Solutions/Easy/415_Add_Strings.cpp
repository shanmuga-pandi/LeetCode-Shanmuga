/*
 Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int m = num1.size();
        int n = num2.size();
        string result;
        int i = m-1;
        int j = n-1;
        while(i >= 0 && j >= 0) {
            char digit = ((carry + (num1[i] - '0') + (num2[j] - '0')) % 10) + '0';
            carry = (carry + (num1[i] - '0') + (num2[j] - '0')) / 10;
            result = digit + result;
            i--;
            j--;
        }
        if (num1.size() != num2.size()) {
            string &rem = num1.size() > num2.size() ? num1 : num2;
            int len = abs((int)(num1.size() - num2.size()));
            for(int i=len-1; i>=0; i--) {
                char digit = ((carry + (rem[i] - '0')) % 10) + '0';
                carry = (carry + (rem[i] - '0')) / 10;
                result = digit + result;
           }
        }
        if (carry)
            result = (char) (carry + '0') + result;

        return result;
    }
};
