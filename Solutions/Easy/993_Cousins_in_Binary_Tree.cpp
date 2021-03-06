/*
 In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 
 
*/

// Time : O(N)
// Space : O(d) D is the max depth
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;
        
        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;
        int xDepth = 0;
        int yDepth = 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                    if (curr->left->val == x) {
                        xParent = curr;
                        xDepth = level + 1;
                    }
                    if (curr->left->val == y) {
                        yParent = curr;
                        yDepth = level + 1;
                    }
                }
                if (curr->right) {
                    q.push(curr->right);
                    if (curr->right->val == x) {
                        xParent = curr;
                        xDepth = level + 1;
                    }
                    if (curr->right->val == y) {
                        yParent = curr;
                        yDepth = level + 1;
                    }
                }
            }
            if (xParent && yParent) {
                if (xParent == yParent)
                    return false;
                if (xDepth != yDepth)
                    return false;
                return true;
            }
        }
        return false;
    }
};
