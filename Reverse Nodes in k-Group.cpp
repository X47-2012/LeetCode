#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode *reverseKGroup(ListNode *head, int k)
 {
 	int n = 0;
 	ListNode * l = head;
 	while(l != NULL)
 	{
 		l = l->next;
 		n++;
 	}
    if(n == 0)
        return NULL;

    if(k == 1 || k == 0 || k > n)
 		return head;

    ListNode * prev = head;
    ListNode * p = prev->next;
    ListNode * q = NULL;
    ListNode * conn = NULL;

 	int m = n / k;
 	head = NULL;

 	for(int i = 1; i <= m; i++)
 	{
 		for(int j = 1; j <= k - 2; j++)
 		{
 			q = p->next;
 			p->next = q->next;
 			q->next = prev->next;
 			prev->next = q;
 		}
 		if(head == NULL)
 			head = prev->next;
        if(conn != NULL)
            conn->next = prev->next;

 		prev->next = p->next;
 		p->next = prev;
        conn = prev;
 		prev = prev->next;
 		if(prev != NULL)
 			p = prev->next;
 	}
 	return head;
 }

 int main()
 {
 	ListNode * head = new ListNode(1);
 	head->next = new ListNode(2);
 	head->next->next = new ListNode(3);
 	head->next->next->next = new ListNode(4);
 	head->next->next->next->next = new ListNode(5);
 	head->next->next->next->next->next = new ListNode(6);

 	ListNode * l = reverseKGroup(head, 3);
 	while(l != NULL)
 	{
 		cout<<l->val<<" ";
 		l = l->next;
 	}
 }
