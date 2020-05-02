/*
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 */

// Time : O(Log n) //update and query
// Space: O(n)

class NumArray {
public:
	NumArray(vector<int> &nums) {
		n = nums.size();
		segtree.resize(2 * n);
		for (int i = n; i < 2 * n; i++) segtree[i] = nums[i - n];
		for (int i = n - 1; i > 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
	}

	void update(int i, int val) {
		int pos = i + n;
		int diff = val - segtree[pos];
		while (pos) {
			segtree[pos] += diff;
			pos /= 2;
		}
	}

	int sumRange(int i, int j) {
		i += n;
		j += n;
		int sum = 0;
		while (i <= j) {
			if ((i % 2) == 1) sum += segtree[i];
			if ((j % 2) == 0) sum += segtree[j];
			i = (i + 1) / 2;
			j = (j - 1) / 2;
		}
		return sum;
	}
private:
	vector<int> segtree;
    int n;
};
