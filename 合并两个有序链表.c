struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }

    struct ListNode* m = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b = m;

    while(list1 && list2)
    {
        if(list1->val > list2->val)
        {
            b->next = list2;
            b = b->next;
            list2 = list2->next;
        }
        else
        {
            b->next = list1;
            b = b->next;
            list1 = list1->next;
        }
    }
    if(list1)
    {
        b->next = list1;
    }
    if(list2)
    {
        b->next = list2;
    }
    m = m->next;
    return m;
}