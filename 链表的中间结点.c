
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* m = head;
    int i = 0;
    while(m)
    {
        i++;
        m = m->next;
    }
    for(int j = 0 ; j < (i/2) ; j++)
    {
        head = head->next;
    }
    return head;

}