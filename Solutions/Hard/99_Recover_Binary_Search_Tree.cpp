/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        vector<TreeNode*> List;
        while(curr != NULL || !stk.empty()) {

            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }


            curr = stk.top();
            stk.pop();
            if (prev && prev->val > curr->val) {
                List.push_back(prev);
                List.push_back(curr);
            }
            prev = curr;
            curr = curr->right;
        }

        int size = List.size();
        // Pick the first one and last one
        if (size >=2 ) {
            int temp = List[0]->val;
            List[0]->val = List[size-1]->val;
            List[size-1]->val = temp;
        }
    }
};
