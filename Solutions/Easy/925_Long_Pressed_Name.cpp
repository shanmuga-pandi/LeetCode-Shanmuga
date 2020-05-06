/*
 Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Constraints:

1 <= name.length <= 1000
1 <= typed.length <= 1000
The characters of name and typed are lowercase letters.
 */

// Time : O(m+n)
// Space : O(1)

class Solution {
public:
    bool checkValid(string &name, string &typed, int m, int n) {
        if (m == 0 && n == 0)
            return true;

        if (m == 0 || n == 0)
            return false;

        if (name[m-1] != typed[n-1])
            return false;


        while(m > 0 && n > 0 && name[m-1] == typed[n-1]) {
            m--;
            n--;
        }

        while(n > 0 && name[m] == typed[n-1])
            n--;

        return checkValid(name, typed, m, n);

    }
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
       return checkValid(name, typed, m , n);
    }
};
