bool hasCycle(struct ListNode *head) {
    if(head == NULL)
    {
        return false;
    }
    if(head->next == NULL)
    {
        return false;
    }
    struct ListNode *n1 = head;
    struct ListNode *n2 = head;
    
    while(n1 && n2 && n2->next)
    {
        n1 = n1->next;
        n2 = n2->next->next;
        if(n1 == n2)
        {
            return true;
        }
    }
    return false;
}