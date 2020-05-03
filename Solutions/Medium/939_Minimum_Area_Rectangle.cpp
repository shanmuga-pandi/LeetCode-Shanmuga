/*
 Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
 */

// Time : O(N^2)
// Space : O(N)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> hash_map;
        for(auto &point:points) {
            hash_map[point[0]].insert(point[1]);
        }
        int ans = INT_MAX;
        for(auto i=begin(hash_map); i!=end(hash_map); i++) {
            for(auto j = next(i); j!=end(hash_map); j++) {
                // Need minimum 2 coordinates to make rectangle
                if (i->second.size() < 2 || j->second.size() < 2)
                    continue;

                vector<int> y;
                // Get common points between the two sets
                set_intersection(begin(i->second), end(i->second) , begin(j->second), end(j->second), back_inserter(y));
                for(int k=1; k<y.size();k++) { // k starts from second point
                    ans = min(ans, abs(i->first - j->first) * (y[k] - y[k-1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
