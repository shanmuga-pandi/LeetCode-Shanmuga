/*
 Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
 */

// Time : O(N)
// Space : O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxPlant = 0;
        int N = flowerbed.size();
        if (n == 0)
            return true;

        if (N == 1)
            return flowerbed[0] == 0;

        for(int i=0; i<N; i++) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (flowerbed[i+1] == 0) {
                        n--;
                        flowerbed[i] = 1;
                    }
                } else if(i == N-1) {
                    if(flowerbed[i-1] == 0) {
                        n--;
                        flowerbed[i] = 1;
                    }
                } else if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n <= 0;
    }
};
