struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = malloc(sizeof(struct ListNode));
    struct ListNode* smallHead = small;
    struct ListNode* large = malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = large;
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = NULL;
    small->next = largeHead->next;
    return smallHead->next;
}
