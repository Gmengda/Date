struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    struct ListNode* m = pListHead;
    int i = 0;
    while(m)
    {
        i++;
        m = m->next;
    }
    if(k > i || k <= 0)
    {
        return 0;
    }
    else
    {
        for(int j = i ; j >= 0 ; j--)
    {
        if(j == k)
        {
            return pListHead;
        }
        pListHead = pListHead->next;
    }
    }
    return pListHead;
}