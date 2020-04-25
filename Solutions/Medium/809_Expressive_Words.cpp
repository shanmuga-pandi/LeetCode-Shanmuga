/*
 Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 

 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
 

Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
 */


// Time Complexity: O(QK), where Q is the length of words (at least 1), and K is the maximum length of a word.

// Space Complexity: O(K).



class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<unordered_map<char, int>> stretchy_list;
        int n = S.length();
        int i = 0;
        int c = 0;
        char prev;
        while(i < n) {
            if (i == 0) {
                prev = S[i];
                c = 1;
                i++;
            }
            while(i < n && prev == S[i]) {
                c++;
                i++;
            }
            //cout << prev << " " << c << "\n";
            stretchy_list.push_back({{prev, c}});
            prev = S[i];
            c = 0;
        }

        int res = 0;
        for(string s: words) {

            int n = s.length();
            int i = 0;
            int c = 0;
            char prev;
            int index = 0;
            int st_size = stretchy_list.size();
            bool success = true;
            while(i < n) {
                if (i == 0) {
                    prev = s[i];
                    c = 1;
                    i++;
                }
                while(i < n && prev == s[i]) {
                    c++;
                    i++;
                }
                //cout << prev << " " << c << "\n";
                //stretchy_list.push_back({{prev, c}});
                if (index < st_size) {
                    //int diff = stretchy_list[index][prev] - c;
                    //cout << prev << " " << c << " diff = " << diff << "\n";
                    //if (diff < 0 || (diff != 0 && diff < 2)) {
                    //    success = false;
                    //    break;
                    //}
                    int strees_count = stretchy_list[index][prev];
                    if (strees_count == 0) {
                        success = false;
                        break;
                    }
                    if (strees_count < c || strees_count < 3 && strees_count != c)
                    {
                        success = false;
                        break;
                    }
                } else {
                    success = false;
                    break;
                }
                prev = s[i];
                c = 0;
                index++;
            }
            if (index != st_size)
                success = false;
            if (success)
                res++;
        }

        return res;
    }
};
