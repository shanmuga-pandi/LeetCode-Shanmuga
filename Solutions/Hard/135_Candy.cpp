/*
 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
 */

// Time : O(N)
// Space : O(N)
class Solution {
public:
    int candy(vector<int>& a) {
        int size = a.size();
          vector<int> res(size);
          res[0]=1;
          for(int i=1;i<size;i++){
              if(a[i] > a[i-1]) {
                  res[i] = res[i-1]+1;
              } else {
                  res[i] = 1;
              }
          }
          for(int i=size-2; i>=0;i--) {
              if(a[i]  > a[i+1]) {
                if(res[i] <= res[i+1]) 
                  res[i] = res[i+1]+1;
              }
          }
          return accumulate(res.begin(), res.end(), 0);
    }
};
