/*
 Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

 

Rules for a valid pattern:

Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.
 


 

Explanation:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

 

Example:

Input: m = 1, n = 1
Output: 9
 */

// Time : O(n!)
// Space : O(n)

class Solution {
public:
   /* void numberOfPatterns(int curr, int count, int m, int n, unordered_set<int> &seen) {
        if (count > n)
            return;

        if (count >= m)
            result++;

        for(int i=1; i<=9; i++) {
            if (seen.count(i) == 0 && (lines_map[curr].count(i) == 0 || seen.count(lines_map[curr][i]) > 0)) {
                seen.insert(i);
               // if (count == 1) {
                //    cout << curr << " " << i << "\n";
                //}
                numberOfPatterns(i, count+1, m, n, seen);
                seen.erase(i);
            }
        }
    }*/

    int numberOfPatterns(int curr, int count, int m, int n, unordered_set<int> &seen) {
        if (count > n)
            return 0;


        int result = 0;
        if (count >= m)
            result++;

        for(int i=1; i<=9; i++) {
            if (seen.count(i) == 0 && (lines_map[curr].count(i) == 0 || seen.count(lines_map[curr][i]) > 0)) {
                seen.insert(i);
                result += numberOfPatterns(i, count+1, m, n, seen);
                seen.erase(i);
            }
        }
        return result;
    }

    int numberOfPatterns(int m, int n) {
        // 1 , 2 , 3
        // 4 , 5 , 6
        // 7 , 8 , 9

        lines_map[1].insert({3,2});
        lines_map[1].insert({7,4});
        lines_map[1].insert({9,5});
        lines_map[2].insert({8,5});
        lines_map[3].insert({1,2});
        lines_map[3].insert({7,5});
        lines_map[3].insert({9,6});
        lines_map[4].insert({6,5});
        lines_map[6].insert({4,5});
        lines_map[7].insert({1,4});
        lines_map[7].insert({3,5});
        lines_map[7].insert({9,8});
        lines_map[8].insert({2,5});
        lines_map[9].insert({1,5});
        lines_map[9].insert({3,6});
        lines_map[9].insert({7,8});

        unordered_set<int> seen;
        final_result = 0;
        if (m == 0)
            final_result++;

	 // Try all numbers as starting point
 /*       for(int i=1;i<=9;i++) {
            seen.insert(i);
            final_result += numberOfPatterns(i, 1, m, n, seen);
            seen.erase(i);
        } */

	// 1 , 3 , 7, 9 are symmetric, so try only one of those
        seen.insert(1);
        final_result += (numberOfPatterns(1, 1, m, n, seen) * 4);
        seen.erase(1);

         // 2 , 4 , 8, 6 are symmetric, so try only one of those
        seen.insert(2);
        final_result += (numberOfPatterns(2, 1, m, n, seen) * 4);
        seen.erase(2);

        // then 5 is remaining
        seen.insert(5);
        final_result += (numberOfPatterns(5, 1, m, n, seen));
        seen.erase(5);

        return final_result;
    }
private:
    int final_result;
    unordered_map<int, unordered_map<int,int>> lines_map;
};
