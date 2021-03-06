/*
 We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
 */


class Solution1 {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())
            return false;
        int N = A.size();
        if (A == B)
            return true;
        for(int i=1; i<=N;i++) {
            rotate(A.begin(), A.begin()+1,A.end());
            if (A == B)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string A, string B) {
        string AA = A + A;
        return A.length() == B.length() && AA.find(B) != std::string::npos;
    }
};
