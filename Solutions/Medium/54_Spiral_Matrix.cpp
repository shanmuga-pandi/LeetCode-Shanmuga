/*
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

//Time : O(M*N)
//Space : O(M*N)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int i=0,j=0;
        int r=matrix.size();
        if(r==0)
            return result;
        int c=matrix[0].size();
        if(c==0)
            return result;
        int dir = 0;
        int k;
        while(r>0 && c>0) {
            switch(dir) {
              case 0: {
                  // move right
                  k=0;
                  while(k < c) {
                      result.push_back(matrix[i][j++]);
                      k++;
                  }
                  j = j-1;
                  i = i+1;
                  r--;
                  dir = 1;
                  break;
              }
              case 1: {
                  k = 0;
                  // move down
                  while(k < r) {
                      result.push_back(matrix[i++][j]);
                    k++;
                  }
                  i = i-1;
                  j = j-1;
                  c--;
                  dir = 2;
                  break;
              }
              case 2: {
                  k = 0;
                  // move left
                  while(k < c) {
                      result.push_back(matrix[i][j--]);
                    k++;
                  }
                  j = j+1;
                  i = i-1;
                  r--;
                  dir = 3;
                  break;
              }

              case 3: {
                  k = 0;
                  // move up
                  while(k < r) {
                      result.push_back(matrix[i--][j]);
                    k++;
                  }
                  i = i+1;
                  j = j+1;
                  c--;
                  dir = 0;
                  break;
              }
            }

        }
        return result;
    }
};
