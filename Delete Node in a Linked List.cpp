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
    void deleteNode(ListNode* node) {
        int num = node->val;

        ListNode *p = node;
        ListNode *q = node->next;
        while (true) {
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
            if ((q->next == NULL) && (q->val == num)) {
                p->next = NULL;
                return;
            }
            p = q;
            q = q->next;
        }
    }
};
