/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

// Time : O(M+N)
// Space : O(max(M,N))

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *head = new ListNode(0);
        ListNode* t = head;
       ListNode *p = l1;
       ListNode *q = l2;a
        int carry = 0;
       while(p && q) {
           int n = p->val + q->val + carry;
           t->next = new ListNode( n % 10) ;
           carry = n / 10;
           p = p->next;
           q = q->next;
           t = t->next;
       }

      ListNode* k = p ? p : q;
      while (k) {
          int n = k->val + carry;
           t->next = new ListNode( n % 10) ;
           carry = n / 10;
           k = k->next;
           t = t->next;
      }

      if (carry)
          t->next = new ListNode( carry) ;
      return head->next;
    }


};
