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
    ListNode* insertionSortList(ListNode* head) {
        if (head || head->next) {
            return head;
        }
        ListNode *p = head, *q = NULL;
        while (p && p->next) {
            ListNode *pSlow = NULL, *pFast = head;
            while (pFast->val < p->val) {
                pSlow = pFast;
                pFast = pFast->next;
            }
            if (pFast->val != p->val) {
                q->next = p->next;
                p->next = pFast;
                if (pSlow) {
                    pSlow->next = p;
                } else {
                    head = p;
                }
            }
            q = p;
            p = p->next;
        }
        return head;
    }
};