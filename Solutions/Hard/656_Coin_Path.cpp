/*
 Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it's not possible to reach the place indexed N then you need to return an empty array.

Example 1:

Input: [1,2,4,-1,2], 2
Output: [1,3,5]
 

Example 2:

Input: [1,2,4,-1,2], 1
Output: []
 

Note:

Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
Length of A is in the range of [1, 1000].
B is in the range of [1, 100].
 */

// Time : O(N.B) B Steps
// Space : O(N)

class Solution {
public:
    // Priority Queue is giving timeOut
    /*vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> res;
        //int cost, vector<int> path
        typedef pair<int, vector<int>> pii;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        if (A[0] == -1)
            return res;
        int n = A.size();
        pq.push({A[0] ,{1}});
        while(!pq.empty()) {
            auto [cost, list] = pq.top();
            pq.pop();
            int index = list.back();
            if (index == n)
                return list;
            for(int i=index+1; i<=n && i<=index+B;i++) {
                if (A[i-1] != -1) {
                    vector<int> newList = list;
                    newList.push_back(i);
                    pq.push({cost+A[i-1], newList});
                }
            }
        }
        return res;
    }*/

    long int minCostJump(vector<int>& A, int B, int i, vector<int>& next) {
        if (i == n-1) {
            if (A[i] != -1)
                return A[i];
            return INT_MAX;
        }
        if (memo[i] != -1)
            return memo[i];

        long int min_cost = INT_MAX;
        for(int j=i+1; j<n && j<=i+B; j++) {
            if (A[j] != -1) {
                long int cost = A[i] + minCostJump(A, B, j, next);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        return memo[i] = min_cost;
    }
    vector<int> cheapestJump(vector<int>& A, int B) {
        n = A.size();
        vector<int> res;
        if (n == 0 || A[0] == -1 || A[n-1] == -1)
            return res;

        vector<int> next(n, -1);
        memo = vector<long int>(n, -1);
        long int cost = minCostJump(A, B, 0, next);
        if (cost >= INT_MAX)
            return res;

        for(int i=0; i<n && next[i] != -1; i=next[i]) {
            res.push_back(i+1);
        }
        res.push_back(n);
        return res;
    }
private:
    int n;
    vector<long int> memo;
};
