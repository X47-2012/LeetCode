ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    ListNode *tmpA = headA, *tmpB = headB;
    int numA = 0, numB = 0;
    while (tmpA != NULL)
    {
        numA++;
        tmpA = tmpA->next;
    }
    while (tmpB != NULL)
    {
        numB++;
        tmpB = tmpB->next;
    }
    tmpA = headA;
    tmpB = headB;
    if (numA >= numB)
    {
        int count = numA - numB;
        while (count-- > 0)
        {
            tmpA = tmpA->next;
        }
    }
    else
    {
        int count = numB - numA;
        while (count-- > 0)
        {
            tmpB = tmpB->next;
        }
    }
    while (tmpA != tmpB && tmpA != NULL)
    {
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    return tmpA;
}
