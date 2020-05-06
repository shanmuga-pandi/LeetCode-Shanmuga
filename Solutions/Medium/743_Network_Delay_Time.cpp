/*
 here are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 */

// Time : O(N Log N)
// Space : O(N + E)

// Dijakstra Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int,int>> adj_list;
        for(auto time : times) {
            adj_list[time[0]][time[1]] = time[2];
        }

        typedef pair<int,int> pi;
        priority_queue<pi , vector<pi>, greater<pi>> pq;
        unordered_set<int> visited;
        int result = 0;

        pq.push({0,K});

        while(!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (visited.count(u) > 0)
                continue;
            visited.insert(u);
            result = max(result, cost);
            for(auto &time: adj_list[u]){
                int v = time.first;
                int w = time.second;
                if (visited.count(v) == 0) {
                    pq.push({cost+w, v});
                }
            }
        }
        return visited.size() == N ? result : -1;
    }
};
