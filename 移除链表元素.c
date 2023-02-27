#include<stdio.h>

struct ListNode* removeElements(struct ListNode* head, int val){
    while (NULL != head && head->val == val) {
        head = head->next;
    }
    
    struct ListNode* cur = head;
    struct ListNode* pre = head;
    while (cur != NULL) {
        if (cur->val == val) {
            pre->next = cur->next;
        } else {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}