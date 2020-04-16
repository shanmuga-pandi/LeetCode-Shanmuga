/*
 Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
 */

// Time : O (N^3)
// Space : O(N^2)
class Solution_Memo {
private:
    unordered_map<string, bool> dp;
public:
    bool checkValidString(string &s, int i, int count) {
        if (i == s.size()) {
            if (count == 0)
                return true;
            return false;
        }

        if (count < 0)
            return false;
        string hash = to_string(i) + "," + to_string(count);
        if (dp.count(hash) > 0)
            return dp[hash];

        char c = s[i];
        if (c == '(') {
            return dp[hash] = checkValidString(s,i+1,count+1);
        } else if (c == ')') {
            return dp[hash] = checkValidString(s,i+1, count-1);
        }

        return dp[hash] = (checkValidString(s,i+1,count+1) || checkValidString(s,i+1,count-1) || checkValidString(s,i+1,count));

    }

    bool checkValidString(string s) {
        return checkValidString(s, 0, 0);
    }
};


// Time : O(N)
// Space : O(1)
class Solution {
public:
    bool checkValidString(string s) {
        // open parentheses count in range [minC, maxC]
        int minC = 0;
        int maxC = 0;
        for(char c: s) {
            if (c == '(') {
                minC++;
                maxC++;
            } else if (c == ')') {
                minC--;
                maxC--;
            } else {
                minC--; // Consider * as ')' , so we need to decrement
                maxC++; // Consider * as '(', so we need to increment
                // if `*` become `` then nothing happens
            }
            if (maxC < 0) return false; // Currently, don't have enough open parentheses to match close parentheses-> Invalid

            minC = max(minC, 0); // minC cannot be negative, if it is negative mean we considered more ')' for '*'
        }
        return minC == 0;
    }
};
