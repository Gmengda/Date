class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if(A==NULL)
            return false;
        else if(A->next==NULL)
            return true;
        //快慢指针找出中间节点
        ListNode* quick=A;
        ListNode* slow=A;
        while(quick!=NULL&&quick->next!=NULL)
        {
            quick=quick->next->next;
            slow=slow->next;
        }
        //反转
        ListNode* p=slow->next;
        ListNode* p1=p->next;      
        while(p!=NULL)
        {
            p->next=slow;
            slow=p;
            p=p1;
            p1=p1->next;
        }
          
        while(A!=slow)
        {
            if((A->val)!=(slow->val))
            {
                return false;
            }else{
                if(A->next==slow)
                {
                    return true;
                }
                A=A->next;
                slow=slow->next;
            }
        }
        return true;
          
    }
};