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

// Solution 1: Segment Tree

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
			if ((i % 2) == 1) sum += segtree[i]; // if left is odd, then parent contains sum outside range, so we include leftSum
			if ((j % 2) == 0) sum += segtree[j]; // if right is even, then parent contains sum outside range, so we include rightSum
            i++;
            j--;
			i = i / 2;
			j = j / 2;
		}
		return sum;
	}
private:
	vector<int> segtree;
    int n;
};


// Solution 2 : Binary Indexed Tree
// Time : O(Log n) //update and query
// Space: O(n)

class NumArray_BIT {
public:
    NumArray_BIT(vector<int>& nums) {
        BuildBITree(nums);
    }

    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        init(i, diff);
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
private:
    void BuildBITree(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        Bitree = vector<int>(n+1, 0);
        for(int i=0; i<n;i++) {
            init(i, nums[i]);
        }
    }
    void init(int index, int value){
        index = index + 1; // BST always 1 indexed.. Index 0 is dummy

        while(index <= n) {
            Bitree[index] += value;
            index = index + (index & -index); // Add last set bit value to move to parent;
        }
    }
    int getSum(int index) {
        int sum = 0;
        index = index + 1;
        while(index > 0) {
            sum += Bitree[index];
            index = index - (index & -index); // subtract set last bit value to move to parent
        }
        return sum;
    }

    vector<int> nums;
    vector<int> Bitree;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
