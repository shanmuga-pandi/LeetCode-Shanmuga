/*
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
 */


class Solution_recu {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.size();
        int m = T.size();
        int i=n-1;
        int j=m-1;
        while(true) {
            if (i >= 0 && S[i] == '#')
                i = handleBackSpace(S, i-1, 1);
            if (j >= 0 &&  T[j] == '#')
                j = handleBackSpace(T, j-1, 1);

           // cout << i << " " << j << "\n";

            if (i >= 0 && S[i] == '#')
                continue;

            if (j >= 0 && T[j] == '#')
                continue;

            if (i < 0 && j < 0)
                return true;

            if (i < 0 || j < 0)
                return false;

            if (S[i] != T[j])
                return false;

            i--;
            j--;
        }

        return true;
    }
private:
    int handleBackSpace(string& s, int pos, int rem) {
        //if (pos < s.size() || pos == 0)
        if (pos < 0)
            return -1;

        if (rem == 0)
            return pos;

        if (s[pos] == '#')
            return handleBackSpace(s, pos-1, rem+1);

        return handleBackSpace(s, pos-1, rem-1);
    }
};


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.size();
        int m = T.size();
        int i=n-1;
        int j=m-1;
        while(i >= 0 || j >= 0) {
            int countSpaces = 0;
            while(i >= 0) {
			    if (S[i] == '#') {
					countSpaces++;
					i--;
				} else if (countSpaces > 0) {
					countSpaces--;
					i--;
				} else
					break;
            }
			countSpaces = 0;
			while(j >= 0) {
			    if (T[j] == '#') {
					countSpaces++;
					j--;
				} else if (countSpaces > 0) {
					countSpaces--;
					j--;
				} else
					break;
            }

            if (i < 0 && j < 0)
                return true;

            if (i < 0 || j < 0)
                return false;

            if (S[i] != T[j])
                return false;
            i--;
            j--;
        }

        if (i >=0 || j >= 0)
            return false;

        return true;
    }
};
