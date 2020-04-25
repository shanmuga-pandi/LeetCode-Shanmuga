/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

// Time : O(N log N)
// Space : O(N)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
       /* sort(intervals.begin(), intervals.end(), [] (auto &l, auto &r) {
            return l[0] < r[0];
        });

        priority_queue<int, vector<int>, greater<int>> min_heap;

        min_heap.emplace(intervals[0][1]);

        for(int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] >= min_heap.top()){
                min_heap.pop();
            }
            min_heap.emplace(intervals[i][1]);
        }

        return min_heap.size(); */

       /* vector<pair<int,int>> times;
        for(auto &interval : intervals) {
            times.emplace_back(interval[0], 1);
            times.emplace_back(interval[1], -1);
        }

        sort(times.begin(), times.end());

        int max_rooms = 0;
        int rooms = 0;
        for(auto &time: times) {
            rooms += time.second;
            max_rooms = max(max_rooms, rooms);
        }
        return max_rooms; */

        map<int,int> room_map;
        for(auto &interval : intervals) {
            room_map[interval[0]] += 1;
            room_map[interval[1]] -= 1;
        }

        int max_rooms = 0;
        int rooms = 0;
        for(auto &time: room_map) {
            rooms += time.second;
            max_rooms = max(max_rooms, rooms);
        }
        return max_rooms;

    }
};
