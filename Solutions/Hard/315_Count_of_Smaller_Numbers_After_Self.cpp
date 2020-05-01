/*
 You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
 */

// Time : O(N log N)
// Space: O(N)

// https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem

class Solution {
public:
    #define iterator vector<vector<int>>::iterator
    void sort_count(iterator l, iterator r, vector<int> &count) {
        if (r - l <= 1)
            return;

        iterator mid = l + (r - l) / 2;
        sort_count(l, mid, count);
        sort_count(mid, r, count);

        for(iterator i=l , j = mid; i<mid; i++) {
            while(j < r && (*i)[0] > (*j)[0])
                j++;
            count[(*i)[1]] += j - mid;
        }
        inplace_merge(l,mid,r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> zipped;
        int n = nums.size();
        for(int i=0; i<n;i++) {
            zipped.push_back({nums[i], i});
        }
        vector<int> count(nums.size(), 0);
        sort_count(zipped.begin(), zipped.end(), count);

        for(int i=0; i<n;i++) {
            cout << zipped[i][0] << "," << zipped[i][1] << " ";
        }
        return count;
    }
};

