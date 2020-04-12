/*
 Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time Complexity : O(N)
// Space : O(N) stack space
// Solution 1: Recursive
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       if (head == NULL)
           return NULL;
        if (head->val == val)
            return removeElements(head->next, val);
        head->next = removeElements(head->next, val);
        return head;
    }
};

// Solution 2: Iterative
// Time : O(N)
// Space : O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       if (head == NULL)
           return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        while(head != NULL) {
            if (head->val != val) {
                prev->next = head;
                prev = head;
            }
            head = head->next;
        }
        prev->next = NULL;
        return dummy->next;
    }
};
