#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int len1=0, len2=0, len=0;
    ListNode *l1_tmp=l1, *l2_tmp=l2;
    while(l1_tmp!=NULL)
    {
        len1++;
        l1_tmp=l1_tmp->next;
    }
    while(l2_tmp!=NULL)
    {
        len2++;
        l2_tmp=l2_tmp->next;
    }
    len=max(len1,len2);
    int *tmp=new int[len+1];
    tmp[len]=0;

    l1_tmp=l1, l2_tmp=l2;
    for(int i=0;i<len;i++)
    {
        if((l1_tmp!=NULL)&&(l2_tmp!=NULL))
        {
            tmp[i]=l1_tmp->val+l2_tmp->val;
            l1_tmp=l1_tmp->next;
            l2_tmp=l2_tmp->next;
        }
        else if((l1_tmp==NULL)&&(l2_tmp!=NULL))
        {
            tmp[i]=l2_tmp->val;
            l2_tmp=l2_tmp->next;
        }
        else if((l2_tmp==NULL)&&(l1_tmp!=NULL))
        {
            tmp[i]=l1_tmp->val;
            l1_tmp=l1_tmp->next;
        }
    }

    for(int i=0;i<len;i++)
    {
        tmp[i+1]+=(int)(tmp[i]/10);
        tmp[i]=tmp[i]%10;
    }

    ListNode *re=new ListNode(0);
    ListNode *re_tmp=re;

    int t;
    if(tmp[len]!=0)
        t=len;
    else
        t=len-1;
    for(int i=0;i<=t;i++)
    {
        re_tmp->next=new ListNode(tmp[i]);
        re_tmp=re_tmp->next;
    }
    return re->next;
}

int main()
{
    ListNode *n1=new ListNode(8);
    n1->next=new ListNode(8);
    ListNode *n2=new ListNode(3);

    ListNode *re=addTwoNumbers(n1,n2);
    while(re!=NULL)
    {
        cout<<re->val;
        re=re->next;
    }
}
