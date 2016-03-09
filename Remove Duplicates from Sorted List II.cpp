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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = head, *q = head;
        bool flag = false;
        head = NULL;
        while (q && q->next) {
            while (q && q->next && (q->val == q->next->val)) {
                flag = true;
                q = q->next;
            }
            
            if (flag) {
                p->next = q->next;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
            if (head == NULL && flag == false) {
                head = p;
            }
            flag = false;
            if (q == NULL || q->next == NULL) {
                break;
            }
        }
        if (head == NULL && flag == false) {
            head = q;
        }
        return head;
    }
};