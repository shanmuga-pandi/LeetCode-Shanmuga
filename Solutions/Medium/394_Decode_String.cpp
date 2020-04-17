/*
 Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

// Time : O(N)
// Space : O(N)

class Solution_recursion {
public:
    string dfs(string &s, int &pos) {
        string word;
        int num = 0;
        while(pos < s.size()) {
            char c = s[pos];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                pos++;
                string res = dfs(s, pos);
                for(int i=0; i<num; i++)
                    word += res;
                num = 0;
            } else if (c == ']') {
                return word;
            } else {
                word += c;
            }
            pos++;
        }
        return word;
    }
    string decodeString(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
};


// Solution 2 : Iterative with stack
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string result;
        stack<int> nums;
        stack<string> chars;
        for(int i=0; i<s.size();i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                nums.push(num);
                chars.push(result);
                num = 0;
                result = "";
            } else if (c == ']') {
                string temp = result;
                result = "";
                int n = nums.top();
                nums.pop();
                for(int j=0; j<n;j++) {
                    result += temp;
                }
                result = chars.top() + result;
                chars.pop();
            } else {
                result += c;
            }
        }
        return result;
    }
};
