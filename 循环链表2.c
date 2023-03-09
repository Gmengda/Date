struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    int j = 1;
    struct ListNode *n1 = head;
    struct ListNode *n2 = head;

    struct ListNode *n = head;
    while(n)
    {
        n1 = n;
        n2 = n;
        while(n1 && n2 && n2->next)
        {
            n1 = n1->next;
            n2 = n2->next->next;
            if(n1 == n || n2 == n)
            {
                return n;
            }
            else if(n1 == n2)
            {
                break;
            }
        }
        n = n->next;
    }
    return NULL;
}