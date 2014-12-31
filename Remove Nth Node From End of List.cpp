#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(head == NULL)
        return NULL;
    ListNode *l = head;
    ListNode *r = head;
    for(int i = 0; i < n; i++)
        r = r->next;
    if(r == NULL)
        return head->next;

    while(r->next != NULL)
    {
        l = l->next;
        r = r->next;
    }
    l->next = l->next->next;
    return head;
}
