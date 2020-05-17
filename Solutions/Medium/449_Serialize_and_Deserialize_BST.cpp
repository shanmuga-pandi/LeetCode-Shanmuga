/*
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */
// Time : O(N)
// Space : O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string doSerialize(TreeNode* root) {
        if (root == NULL)
            return "#";
        string str = to_string(root->val);
        str = str + " " + doSerialize(root->left);
        str = str + " " + doSerialize(root->right);
        return str;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return doSerialize(root);
    }

    TreeNode* doDesrialize(stringstream &str) {
        string word;
        getline(str,word,' ');
        if (word == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(word));
        root->left = doDesrialize(str);
        root->right = doDesrialize(str);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str(data);
        return doDesrialize(str);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
