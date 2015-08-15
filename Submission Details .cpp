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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* l = head;
        while(head->next != NULL) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = l;
            l = tmp;
        }
        head->next = NULL;
        return l;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head;
        if (head == NULL || head->next == NULL) {
            return true;
        }

        while (q != NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
        }

        if (q != NULL) {
            p = p->next;
        }

        ListNode *l = reverseList(p);
        while (l != NULL) {
            if (head->val != l->val) {
                return false;
            }
            l = l->next;
            head = head->next;
        }
        return true;
    }
};
