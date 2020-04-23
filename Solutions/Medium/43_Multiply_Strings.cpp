/*
 Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

// Time : O(M*N)
// Space : O(D)

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        if (num1.length() < num2.length())
            swap(num1, num2);

        string prevSum;
        int prevStartIndex;
        int carry = 0;
        int m = num2.length();
        int n = num1.length();
        int a , b, c;
        string curr;
        int skip = 0;
        for(int i=m-1; i >= 0; i--) {
            a = num2[i] - '0';
            prevStartIndex = prevSum.size() - skip - 1;
            curr = prevSum.substr(prevStartIndex+1);
            reverse(curr.begin(), curr.end());
            for(int j=n-1; j>=0; j--) {
                b = num1[j] - '0';
                c = prevStartIndex >= 0 ? prevSum[prevStartIndex] - '0' : 0;
                int prod = (a * b) + carry + c;
                carry = prod / 10;
                prod = prod % 10;
                //curr = static_cast<char>(prod + '0') + curr;
                curr += static_cast<char>(prod + '0');
                prevStartIndex--;
            }
            skip++;
            if (carry != 0) {
                //curr = static_cast<char>(carry + '0') + curr;
                curr += static_cast<char>(carry + '0');
                carry = 0;
            }
            reverse(curr.begin(), curr.end());
            prevSum = curr;
        }

        return prevSum;
    }
};
