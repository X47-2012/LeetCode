ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    if (len <= 2) {
        return head;
    }
    ListNode* p = head;
    ListNode* q = p->next;
    int count = 0;
    while (count++ < (len / 2)) {
        p->next = q->next;
        tail->next = q;
        q->next = NULL;
        p = p->next;
        q = p->next;
        tail = tail->next;
    }
    return head;
}