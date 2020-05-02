/*
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> char_map;
        char_map['0'] = '0';
        char_map['1'] = '1';
        char_map['6'] = '9';
        char_map['8'] = '8';
        char_map['9'] = '6';

        int n = num.size();
        if (n == 0)
            return true;
        if (n == 1)
            return num == "1" || num == "0" || num == "8";

        int l = 0;
        int r = n-1;

        while(l <= r) {
            if (char_map[num[l]] != num[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
