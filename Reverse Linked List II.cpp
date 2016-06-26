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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* l = head;
        ListNode* ll = NULL;
        int i = 0;
        while (++i < m && l) {
            ll = l;
            l = l->next;
        }
        if ((i >= n) || (l == NULL)) {
            return head;
        }
        ListNode* p = l->next;
        ListNode* q = NULL;
        i = m;
        while (++i < n && p && p->next) {
           q = p->next;
           p->next = q->next;
           q->next = l->next;
           l->next = q;
        }
        if (ll == NULL) {
            head = l->next;
            l->next = p->next;
            p->next = l;
            return head;
        } else {
            ll->next = l->next;
            l->next = p->next;
            p->next = l;
            return head;
        }
    }
};