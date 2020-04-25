/*
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 */

// Time Complexity: O(1). We try up to 24∗60 possible times until we find the correct time.
// Space : O(1)
class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> all_valid;

        for(int i=0; i<time.size();i++) {
            if (time[i] != ':') {
                all_valid.emplace(time[i] - '0');
            }
        }
        int hour = stoi(time.substr(0,2));
        int mins = stoi(time.substr(3,2));
        while(true) {
            mins++;
            if (mins == 60) {
                mins = 0;
                hour++;
                if (hour == 24)
                    hour = 0;
            }
            if (all_valid.count(hour/10) &&  all_valid.count(hour%10) && all_valid.count(mins/10) && all_valid.count(mins%10)) {
                break;
            }
        }

        string hr = (hour < 10) ? "0" + to_string(hour): to_string(hour);
        string mn = (mins < 10) ? "0" + to_string(mins): to_string(mins);
        return hr + ":" + mn;
    }
};
