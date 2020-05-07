/*
 Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
 */

// Time : O(n log n) // for sort
// Space : O(n)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n <= 1)
            return 0;
        vector<int> times;
        for(int i=0; i<n;i++) {
            int hour = stoi(timePoints[i].substr(0,2));
            int min = stoi(timePoints[i].substr(3));

            times.push_back(hour * 60 + min);
            times.push_back((hour + 24) * 60 + min);
        }
        sort(times.begin(), times.end());
        int min_result = INT_MAX;
        for(int i=1;i<times.size();i++) {
            min_result = min(min_result, times[i] - times[i-1]);
        }
        return min_result;
    }
};
