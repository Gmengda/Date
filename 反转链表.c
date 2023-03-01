#include<stdio.h>

struct ListNode* reverseList(struct ListNode* head){

    struct ListNode* temp;
    struct ListNode* pre = NULL;

    while(head) 
    {

        temp = head->next;
        head->next = pre;

        pre = head;
        head = temp;
    }
    
    return pre;
}
