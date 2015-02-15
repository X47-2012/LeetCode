#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
	bool operator () (ListNode * const &p1, ListNode * const &p2)
	{
		return p1->val > p2->val;
	}
};


ListNode * mergeKLists(vector<ListNode *> &lists)
{
    if(lists.size() == 0)
        return NULL;

	priority_queue<ListNode *, vector<ListNode *>, cmp> heap;
	ListNode * head = NULL;
	ListNode * p = NULL;

	for(int i = 0; i < lists.size(); i++)
	{
	    if(lists != NULL)
            heap.push(lists[i]);
	}

	while(!heap.empty())
	{
		if(head == NULL)
		{
			head = heap.top();
			p = head;
		}
		else
		{
			p->next = heap.top();
			p = p->next;
		}

		if(heap.top()->next != NULL)
		{
			heap.push(heap.top()->next);
		}
		heap.pop();
	}

	return head;
}

int main()
{
	vector<ListNode *> lists;
	ListNode * head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);

	ListNode * head2 = new ListNode(4);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(8);

	ListNode * head3 = new ListNode(5);
	head3->next = new ListNode(7);
	head3->next->next = new ListNode(9);

	lists.push_back(head1);
	//lists.push_back(head2);
	//lists.push_back(head3);

	ListNode * head = mergeKLists(lists);
	while(head != NULL)
	{
		cout<<head->val<<"  ";
		head = head->next;
	}
	return 0;
}
