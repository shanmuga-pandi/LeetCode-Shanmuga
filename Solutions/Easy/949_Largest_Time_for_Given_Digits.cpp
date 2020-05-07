/*
 Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9
 */

// Time : O(1) -> since the i/p size is always 4
// Space : O(1)

class Solution {
public:
    void permutation(vector<int> &A, vector<int>& added, unordered_set<int> &seen) {
        if (added.size() == 4) {
            int hour = A[added[0]] * 10 + A[added[1]];
            int minutes = A[added[2]] * 10 + A[added[3]];
            if (hour > 23 || minutes > 59)
                return;
            //cout << A[added[0]] << " " << added[1] << " " << added[2] << " " << added[3] << "\n";
            result = max(result, hour*60+minutes);
            return;
        }
        for(int i=0; i<4;i++) {
            if (seen.count(i) == 0) {
                seen.insert(i);
                added.push_back(i);
                permutation(A, added, seen);
                added.pop_back();
                seen.erase(i);
            }
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        result = INT_MIN;
        vector<int> added;
        unordered_set<int> seen;
        permutation(A, added, seen);
        if (result == INT_MIN)
            return "";

        int hour = result / 60;
        int mins = result % 60;
        string hr = to_string(hour);
        string mn = to_string(mins);
        if (hour < 10)
            hr = "0" + hr;
        if (mins < 10)
            mn = "0" + mn;

        return hr + ":" + mn;
    }
 private:
    int result;
};
