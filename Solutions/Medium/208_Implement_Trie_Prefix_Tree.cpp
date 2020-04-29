/*
 Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
 */

// Time : O( N * L) L is length of word
// Space : O( N * L)

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
            if (curr->children[c-'a'] == NULL) {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word) {
            if (curr->children[c-'a'] == NULL) {
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return curr->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix) {
            if (curr->children[c-'a'] == NULL) {
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return true;
    }
private:
    struct TrieNode{
        bool isLeaf;
        TrieNode* children[26];
    };

    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
