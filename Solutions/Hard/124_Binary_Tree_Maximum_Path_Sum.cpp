/*
 Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long int pathSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        result = max(result, (long int) root->val);

        if (root->left == NULL && root->right == NULL)
            return root->val;

        long int leftSum = pathSum(root->left);
        long int rightSum = pathSum(root->right);
        long int sum = root->val + leftSum + rightSum;


        long int maxSum = leftSum + root->val;
        maxSum = max(maxSum,  rightSum + root->val);
        maxSum = max(maxSum,  (long int) root->val);

        //cout << maxSum << " " << sum << "\n";

        result = max(result, maxSum);
        result = max(result, sum);

        return maxSum;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return INT_MIN;
        result = LONG_MIN;
        pathSum(root);
        return result;
    }
private:
    long int result;
};
