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
        if (head ==NULL || head->next == NULL){
        return head;
    }
    ListNode *current;
    ListNode *prev;
    ListNode dummy(0);
    dummy.next = head;
    prev = head;
    current = head->next;
    while(current){
        if (current->val >= prev->val){
            prev = current;
            current = current->next;
            continue;
        }

        ListNode *temp = current;

        prev->next  = current->next;
        current = current->next;


        ListNode *innerCurr = dummy.next;
        ListNode *innerPrev = &dummy;


        while(temp->val >= innerCurr->val){
            innerPrev = innerCurr;
            innerCurr = innerCurr->next;
        }

        temp->next = innerCurr;
        innerPrev->next = temp;
    }
    return dummy.next;  
}
};