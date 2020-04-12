/*
 Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Time Complexity : O(N), Where N is no of nodes.
// Space Complexity : O(N), Recursice stack space
class Solution {
public:
    bool recursiveCheck(ListNode* head) {
        if (head == NULL)
            return true;

        if (!recursiveCheck(head->next))
            return false;
        if (frontNode->val != head->val)
            return false;

        frontNode = frontNode->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;

        frontNode = head;
        return recursiveCheck(head);
    }
private:
    ListNode* frontNode;
};



// TODO: 
// Another Approach can try for O(1) space complexity
/*

Specifically, the steps we need to do are:

Find the end of the first half.
Reverse the second half.
Determine whether or not there is a palindrome.
Restore the list.
Return the result.
*/
