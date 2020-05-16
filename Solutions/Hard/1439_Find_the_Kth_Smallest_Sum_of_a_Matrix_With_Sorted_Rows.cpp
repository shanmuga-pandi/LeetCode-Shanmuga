/*
 You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

 

Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
Example 2:

Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17
Example 3:

Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
Example 4:

Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
 

Constraints:

m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] is a non decreasing array.
 */

// Time : O(M * N * K * log(k))
// Space : O(K)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int R = mat.size();
        int C = mat[0].size();
        priority_queue<int> pq;
        for(int i=0; i<C && i<k ;i++) {
            pq.push(mat[0][i]);
            if (pq.size() > k)
                pq.pop();
        }
        for(int i=1; i<R;i++) {
            priority_queue<int> next_pq;
            while(!pq.empty()) {
                int t = pq.top();
                pq.pop();
                for(int j=0; j<C && j < k;j++) {
                     int val = mat[i][j] + t;
                     if (next_pq.size() < k) {
                         next_pq.push(val);
                     } else if (val < next_pq.top()) {
                         next_pq.pop();
                         next_pq.push(val);
                     }
                }
            }
            pq = next_pq;
        }
        return pq.top();
    }
};

// This code is much faster

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
		int m = mat.size(), n = mat[0].size();
		vector<int> tmp(k, 5001);
		for(int j =0;j<n && j< k;++j){
			tmp[j] = mat[0][j];
		}
		priority_queue<int> pq;//max_heap
		for (int i = 1; i < m;++i){
			for (int j = 0; j < n && j < k;++j){
				for (int s = 0; s < k;++s){
					int val = tmp[s] + mat[i][j];
					if(pq.size() < k){
						pq.push(val);
					}
					else if(val < pq.top()){
						pq.pop();
						pq.push(val);
					}
				}
			}
			int tmp_j = pq.size();
			while(!pq.empty()){
				tmp[--tmp_j] = pq.top();
				pq.pop();
			}
		}
		return tmp[k-1];
	}
};
