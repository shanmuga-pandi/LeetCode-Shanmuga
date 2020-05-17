/*
 Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 */

// Time : O(N)
// Space : O(N)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> list;
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        if (store.count(key) == 0) {
            insert_word(key);
        }
        store[key] = val;
    }

    int sum(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix) {
            if (curr->children.count(c) == 0)
                return 0;;
            curr = curr->children[c];
        }
        int sum = 0;
        for(string &s:curr->list) {
            sum += store[s];
        }
        return sum;
    }
private:
    void insert_word(string &word) {
        TrieNode *curr = root;
        for(char c: word) {
            if (curr->children.count(c) == 0)
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
            curr->list.push_back(word);
        }
    }
    TrieNode* root;
    unordered_map<string,int> store;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
