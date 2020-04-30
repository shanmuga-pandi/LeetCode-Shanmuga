/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */

// Time : O(N)
// Space : O(N)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> startInterval;
        vector<int> lastInterval;
        bool startFound = false;
        bool added_interval = false;

        vector<vector<int>> result;

        for(auto &interval : intervals) {
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
                continue;
            }
            if (interval[0] > newInterval[1]) {
                if (!added_interval) {
                    int x = startFound ? min(startInterval[0], newInterval[0]) : newInterval[0];
                    int y = startFound ? max(lastInterval[1], newInterval[1]) : newInterval[1];
                    result.push_back({x,y});
                    added_interval = true;
                }
                result.push_back(interval);
                continue;
            }

            //if (!startFound && interval[0] <= newInterval[0] && interval[1] >= newInterval[0]) {
            if (!startFound) {
                startFound = true;
                startInterval = interval;
                lastInterval = startInterval;
            }

             lastInterval = interval;
        }

       // cout << startFound;
        if (!added_interval) {
            int x = startFound ? min(startInterval[0], newInterval[0]) : newInterval[0];
            int y = startFound ? max(lastInterval[1], newInterval[1]) : newInterval[1];
            result.push_back({x,y});
        }
        return result;
    }
};
