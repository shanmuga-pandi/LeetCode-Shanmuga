/*
 Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
 */

// Time : Time Complexity: (|E|^d) where |E| is the number of total flights and d is the maximum number of flights from an airport.
// Space :O(|V| + |E|) where |V| is the number of airports and |E| is the number of flights.

class Solution {
public:
    bool dfs(string start, unordered_set<int> &seen, vector<string>&list) {
        if (seen.size() == n) {
            result = list;
            return true;
        }

        for(auto &to: adj_list[start]) {
            if (seen.count(to.second) == 0) {
                seen.insert(to.second);
                list.push_back(to.first);
                if (dfs(to.first, seen, list))
                    return true;
                seen.erase(to.second);
                list.pop_back();
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for(int i=0; i<n; i++){
            auto &ticket = tickets[i];
            adj_list[ticket[0]].emplace(ticket[1] , i);
        }
        unordered_set<int> seen;
        vector<string> list;
        list.push_back("JFK");
        dfs("JFK", seen, list);
        return result;
    }
private:
    unordered_map<string, multimap<string,int>> adj_list;
    vector<string> result;
    int n;
};
