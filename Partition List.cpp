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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *small = NULL, *big = NULL, *smallP = NULL, *bigP = NULL;
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                if (small == NULL) {
                    small = p;
                    smallP = p;
                } else {
                    smallP->next = p;
                    smallP = smallP->next;
                }
            } else {
                if (big == NULL) {
                    big = p;
                    bigP = p;
                } else {
                    bigP->next = p;
                    bigP = bigP->next;
                }
            }
            p = p->next;
        }
        if (smallP) {
            smallP->next = big;
        }
        if (bigP) {
            bigP->next = NULL;
        }
        return (small != NULL) ? small : big;
    }
};