
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* cur = pHead;
        ListNode* shead,*stail,*mhead,*mtail;
        shead = stail = (ListNode*)malloc(sizeof(ListNode));
        mhead = mtail = (ListNode*)malloc(sizeof(ListNode));
        stail->next = NULL;
        mtail->next = NULL;
        while(cur){
            if(cur->val < x){
                stail ->next = cur;
                stail = cur;
            }
            else{
                mtail ->next = cur;
                mtail = cur;
            }
            cur = cur->next;
        }
         
        stail ->next = mhead->next;
        mtail -> next = NULL;
        ListNode* tmp = shead->next;
        free(shead);
        free(mhead);
        return tmp;
        
        // write code here
    }
};