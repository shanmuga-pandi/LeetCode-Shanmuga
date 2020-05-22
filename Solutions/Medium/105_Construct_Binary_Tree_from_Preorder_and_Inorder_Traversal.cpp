/*
 Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */

// Time : O(N)
// Space : O(N)

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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (preStart == preorder.size() || inStart >= inEnd)
            return NULL;


        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        // find root in inOrder
        for(int i=inStart; i<inEnd; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }

        int distance = inIndex - inStart;
        root->left = helper(preorder,inorder, preStart+1, inStart, inIndex);
        root->right = helper(preorder,inorder, preStart+distance+1, inIndex+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size());
    }
};


// Improved version using hashmap
//
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (preStart == preorder.size() || inStart >= inEnd)
            return NULL;
        
       
        TreeNode *root = new TreeNode(preorder[preStart]);
        // Find index from inorder
        int inIndex = inMap[root->val];
  
	int distance = inIndex - inStart;
        root->left = helper(preorder,inorder, preStart+1, inStart, inIndex);
        root->right = helper(preorder,inorder, preStart+distance+1, inIndex+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {       

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, 0, inorder.size());
    }
private:
    unordered_map<int, int> inMap;
};
