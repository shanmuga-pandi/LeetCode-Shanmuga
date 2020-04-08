/*
 Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;
        int curr_len = words[0].size();
        int start = 0;
        int end = 0;
        for(int i=1 ; i<n ; i++) {
            string& word = words[i];
            int word_size = word.size();
            if (curr_len + word_size + 1 <= maxWidth) {
                curr_len = curr_len + word_size + 1;
                end = i;
            } else {
                string str = formString(words, start,end, maxWidth - curr_len);
                result.push_back(str);
                curr_len = word.size();
                start = i;
                end = i;
            }
        }

        string str = formString(words, start,end, 0);
        str += string(maxWidth - curr_len, ' ');
        result.push_back(str);

        return result;
    }
private:
    string formString(vector<string>& words, int start, int end, int remaining_spaces) {
       // cout << remaining_spaces << "\n ";
        int n = end - start;
        if (n == 0)
            return words[start] + string(remaining_spaces, ' ');

        int extraSpacesForEachWord = 1 + (remaining_spaces / n);
        int oneExtraSpaceTill = remaining_spaces % n;
        string str= words[start];
        for(int i=1; i<=n;i++) {
            int space = extraSpacesForEachWord;
            if (i <= oneExtraSpaceTill)
                space += 1;
            str += string(space, ' ') + words[start+i];
        }
        return str;
    }
};
