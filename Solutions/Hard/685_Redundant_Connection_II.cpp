/*
 In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 */

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
       vector<int> dummy(2,0);
         int N = edges.size();
        int mutipleIncomingEdge = -1;
        vector<int> incoming(N+1, 0);
        // Check any vertex has more than 1 incoming path
        for(auto &edge: edges) {
            incoming[edge[1]]++;
            if (incoming[edge[1]] > 1) {
                mutipleIncomingEdge = edge[1];
                break;
            }
        }
        // If no vertex has more than 1 incoming path, then just detect cycle
        if (mutipleIncomingEdge == -1)
         return detectCycle(edges, dummy);

        // Check detect cycle after removing incoming edge
        // If it is not forming cycle, then this the edge to be removed
        for(int i= N-1; i>=0; i--) {
            if (edges[i][1] == mutipleIncomingEdge) {
                vector<int> res = detectCycle(edges, edges[i]);
                if (res.empty())
                    return edges[i];
            }
        }
        return vector<int>();
    }
private:
    vector<int> detectCycle(vector<vector<int>>& edges, vector<int> &skipEdge)     {
        int N = edges.size();
        parent = vector<int>(N+1);
        rank = vector<int>(N+1);
        init();
        vector<int> result;
        for(auto &edge : edges) {
            if (edge[0] == skipEdge[0] && edge[1] == skipEdge[1])
                continue;
            bool res = Union(edge[0], edge[1]);
            if (res == false)
                result = edge;
        }
        return result;
    }
     vector<int> parent;
     vector<int> rank;
     void init() {
         for(int i=1; i<parent.size(); i++)
         {
             parent[i] = i;
             rank[i] = 0;
         }
     }
     int find(int v) {
         if (parent[v] == v)
             return v;

         parent[v] = find(parent[v]);
         return parent[v];
     }
     int Union(int x, int y) {
         int xRoot = find(x);
         int yRoot = find(y);
         //cout << x << " " << y << "\n";
         //cout << " xRoot " << xRoot << " yRoot " << yRoot << "\n";
         if (xRoot == yRoot) // Cycle detected.
             return false;

         if (rank[xRoot] > rank[yRoot]) {
             parent[yRoot] = xRoot;
         } else if (rank[yRoot] > rank[xRoot]) {
             parent[xRoot] = yRoot;
         } else {
             parent[yRoot] = xRoot;
             rank[xRoot]++;
         }
         return true;
     }
};
