/*
 Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
 */


class Solution {
public:
    // Do DFS from start to end 
    double getResult(const string &start, const string &end, unordered_set<string> &visited, unordered_map<string, unordered_map<string, double>> &graph) {
        if (graph.count(start) == 0)
            return -1;
        
        if (graph[start].count(end) > 0)
            return graph[start][end];
        
        visited.insert(start);
        unordered_map<string, double> &adj_list = graph[start];
        for(auto it: adj_list) {
            if (visited.count(it.first) == 0) {
                double result = getResult(it.first, end, visited, graph);
                if (result != -1)
                    return result * it.second;
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> result;
        
        // Build Graph
        for(int i=0; i<equations.size();i++) {
            // Logic behind this if a / b = 2, then b / a = 1 / 2
            graph[equations[i][0]].insert({equations[i][1], values[i]}); 
            graph[equations[i][1]].insert({equations[i][0], 1 / values[i]}); 
        }
        
        for(int i=0; i<queries.size();i++) {
            unordered_set<string> visited;
            result.push_back(getResult(queries[i][0], queries[i][1], visited, graph));
        }
        return result;
    }
};
