/*
 There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
 */

// Using Sort
// // TIME : O(n log n)
// Space : O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by CostA - CostB
        sort(costs.begin(), costs.end() , [] (auto &lhs, auto &rhs){
            return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
        });

        // Send first half persons to A, rest half to B
        int totalCost = 0;
        int n = costs.size() / 2; // Divide half
        for(int i=0; i<n; i++) {
            totalCost += costs[i][0]; // Costs for A
            totalCost += costs[i+n][1]; // Costs for B
        }
        return totalCost;
    }
};


// Using nth_element
// TIME : O(n log n)
// Space : O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // nth_element : Use Quick Select agorithm , left side Middle will have lesser than middle, right side will have greater
        nth_element(costs.begin(), costs.begin() + costs.size() / 2, costs.end() , [] (auto &lhs, auto &rhs){
            return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
        });

        // Send first half persons to A, rest half to B
        int totalCost = 0;
        int n = costs.size() / 2; // Divide half
        for(int i=0; i<n; i++) {
            totalCost += costs[i][0]; // Costs for A
            totalCost += costs[i+n][1]; // Costs for B
        }
        return totalCost;
    }
};
