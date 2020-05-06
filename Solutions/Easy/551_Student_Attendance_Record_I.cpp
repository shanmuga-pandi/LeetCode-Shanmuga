/*
 You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
 */

// Time : O(N)
// Space : O(1)

class Solution {
public:
    bool checkRecord(string s) {
        bool isAbsenceOnce = false;
        int i = 0;
        int n = s.size();
        int lateCount = 0;
        while(i < n) {
            if (s[i] == 'A') {
                if (isAbsenceOnce)
                    return false;
                isAbsenceOnce = true;
            } else if (s[i] == 'L') {
                while(i < n && s[i] == 'L') {
                    lateCount++;
                    i++;
                    if (lateCount > 2)
                        return false;
                }
                i--;
                lateCount = 0;
            }
            i++;
        }
        return true;
    }
};
