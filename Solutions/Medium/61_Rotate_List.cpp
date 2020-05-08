/*
 Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */

// Time: O(N)
// Space : O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        ListNode* fast = head;        
        int i = 0;
        while(fast && i<k) {
            fast = fast->next;
            i++;
        }
        if (fast == NULL) {
            k = k % i;
            if (k == 0)
                return head;
            i = 0;
            fast = head; 
            while(fast && i<k) {
                fast = fast->next;
                i++;
            }
        }
        ListNode* slow = head;        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
    }
};
