/*
 Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
 */

class DJU {
public:
    DJU(int N) {
        parent = vector<int>(N);
        ranks = vector<int>(N, 0);
        for(int i=0; i<N; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return false;
        if (ranks[xRoot] > ranks[yRoot]) {
            parent[yRoot] = xRoot;
        } else if (ranks[yRoot] > ranks[xRoot]) {
            parent[xRoot] = yRoot;
        } else {
            parent[yRoot] = xRoot;
            ranks[xRoot]++;
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> ranks;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DJU dju = DJU(accounts.size());
        unordered_map<string, int> email_maps;
        for(int k=0; k<accounts.size(); k++) {
            auto &account = accounts[k];
            string &name = account[0];
            for(int i=1; i<account.size(); i++) {
                string &email = account[i];
                if (email_maps.count(email) > 0) {
                    int acc_no = email_maps[email];
                    //if(accounts[acc_no][0] == name) {
                        dju.Union(acc_no, k);
                    //}
                }
                email_maps[email] = dju.find(k);
            }
        }

        unordered_map<int, set<string>> name_maps;
        for(auto &email:email_maps) {
            //cout << email.first << " " << email.second << "\n";
             name_maps[dju.find(email.second)].emplace(email.first);
        }


        vector<vector<string>> result;
        for(auto &names : name_maps) {
            string name = accounts[names.first][0];
            vector<string> email_list;
            email_list.push_back(name);
            set<string> &emails = names.second;
            email_list.insert(email_list.end(),emails.begin(), emails.end());
            result.push_back(email_list);
        }
        return result;
    }
};

