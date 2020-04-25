/*
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */

/*
Time complexity : O(Nlogk) where k is the number of linked lists.

The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. But finding the node with the smallest value just costs O(1)O(1) time.
There are NN nodes in the final linked list.
*/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct nodecmp {
            bool operator() (ListNode* left, ListNode* right) {
                return left->val > right->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*> , nodecmp> pq;
        for(auto list: lists) {
            if (list)
                pq.push(list);
        }

        ListNode* result = new ListNode(0);
        ListNode* head = result;
        while(!pq.empty()) {
            ListNode* list = pq.top();
            pq.pop();
            head->next = list;
            head = head->next;
            list = list->next;
            if (list)
                pq.push(list);
        }
        head->next = NULL;
        return result->next;
    }
};
