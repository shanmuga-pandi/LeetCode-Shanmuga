/*
 Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
 */

// Time : O(N * (M+N))
// Space : O(M+N)

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1;
        string as = A;
        int len = A.size();
        int m = len;
        int n = B.size();
	// Fill as long as size is less the B size
        while(len < n ) {
            as += A;
            len += m;
            count++;
        }
        if (as.find(B) != -1)
            return count;
        as += A;
        if (as.find(B) != -1)
            return count+1;
        return -1;
    }
};
