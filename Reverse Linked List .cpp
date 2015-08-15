#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main() {

}
