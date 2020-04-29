/*
 Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
 */

// Time : O(M(4⋅3 ^ L−1)) // M is total no of cell, L is max lenth of word
// Space : O(N) Total no of letters
//
struct TrieNode{
        string word;
        unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = word;
    }
    
    TrieNode* getRoot() { return root;}
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    Solution() {
        root = new Trie();
    }
    
    void backtracking(vector<vector<char>>& board, int row, int col, TrieNode* parent) {
        char c = board[row][col];
        TrieNode *curr = parent->children[c];
        
        // Check if there is any word found
        if (curr->word != "") {
            result.push_back(curr->word);
            curr->word = "";
        }
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        
        board[row][col] = '#'; // Mark this item as seen
        
        for(int d=0; d<4; d++) {
            int i = row + dx[d];
            int j = col + dy[d];
            if (i < 0 || i >= m || j < 0 || j >= n)
                continue;
            if (curr->children.count(board[i][j]) > 0)
                backtracking(board, i,j,curr);
        }
        
        board[row][col] = c; // Backtracking
        
        // Optimization: incrementally remove the leaf nodes
        if (curr->children.empty()) {
           parent->children.erase(c);
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if (m == 0)
            return result;
        n = board[0].size();
        if (n == 0)
            return result;
        
        //Construct Trie
        for(string& word: words) {
            root->insert(word);
        }
        
        for(int i=0; i<m;i++) {
            for(int j=0;j<n;j++) {
                char c = board[i][j];
                if (root->getRoot()->children.count(c) > 0)
                    backtracking(board, i,j,root->getRoot());
            }
        }
        return result;
    }
    
private: 
    Trie *root;
    vector<string> result;
    int m,n;
};
