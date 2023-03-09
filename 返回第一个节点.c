struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{   
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    int i = 0;
    int n = 0;
    int m = 0;
    struct ListNode*a = headA;
    struct ListNode*b = headB;
    struct ListNode*c = headA;
    struct ListNode*d = headB;
    while(a)
    {
        a = a->next;
        i++;
    }
    while(b)
    {
        b = b->next;
        n++;
    }
    if(i > n)
    {
        m = i - n;
        while(m--)
        {
            c = c->next;
        }
    }
    else
    {
        m = n - i;
        while(m--)
        {
            d = d->next;
        }
    }
    while(c && d)
    {
        if(c == d)
        {   
            return c;
        }
        else
        {
            c = c->next;
            d = d->next;
        }
    }
    return NULL;
}