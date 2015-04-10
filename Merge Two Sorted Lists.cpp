#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
   	ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode * head = NULL;
	ListNode * p = head;
	while(l1 != NULL || l2 != NULL)
	{
		int val = 0;
		if(l1 == NULL)
		{
			val = l2->val;
			l2 = l2->next;
		}
		else if(l2 == NULL)
		{
			val = l1->val;
			l1 = l1->next;
		}
		else
		{
			if(l1->val <= l2->val)
			{
				val = l1->val;
				l1 = l1->next;
			}
			else
			{
				val = l2->val;
				l2 = l2->next;
			}
		}

		ListNode * tmp = new ListNode(val);
		if(head == NULL)
		{
			head = p = tmp;
		}
		else
		{
			p->next = tmp;
			p = p->next;
		}
	}

	return head;
}

int main()
{
	ListNode * head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);

	ListNode * head2 = new ListNode(3);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(6);

	ListNode * merged = mergeTwoLists(head1, head2);
	while(merged != NULL)
	{
		printf("%d\n", merged->val);
		merged = merged->next;
	}
	return 0;
}