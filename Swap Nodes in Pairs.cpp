#include <iostream>
using namespace std;

struct ListNode
{
 	int val;
	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode *swapPairs(ListNode *head)
 {
 	if(head == NULL)
 		return NULL;
    if(head->next == NULL)
        return head;

 	ListNode * p = head;
 	ListNode * q = p->next;
 	ListNode * prev = NULL;
    head = NULL;

 	while(p != NULL && q != NULL)
 	{
 		p->next = q->next;
 		q->next = p;
 		if(prev != NULL)
 			prev->next = q;
 		if(head == NULL)
 			head = q;
 		prev = p;
 		p = p->next;
 		if(p != NULL)
 			q = p->next;
 	}
 	return head;
 }

 int main()
 {
 	ListNode * head = new ListNode(1);
 	head->next = new ListNode(2);
 	head->next->next = new ListNode(3);
 	head->next->next->next = new ListNode(4);

 	ListNode * l = swapPairs(head);
 	while(l != NULL)
 	{
 		cout<<l->val<<" ";
        l = l->next;
 	}
 }
