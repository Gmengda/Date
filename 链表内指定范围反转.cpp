/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(!head) return head;
        if(m <= 0  || n <=0) return head;
        if(m >= n) return head;
        ListNode* left = head;
        ListNode* right = NULL;
        ListNode* begin = head;
        ListNode* end = head;
        if(m == 1)
        {
            left = NULL;
            begin = head;
        }
        else 
        {
            while((m > 2) && left)
            {
                left = left->next;
                m--;
            }
            if(!left) return head;
            begin = left->next;
            if(!begin) return head;
        }

        while(n > 1 && end)
        {
            end = end->next;
            n--;
        }
        if(!end) return head;
        right = end->next;

        ListNode* pre = NULL;
        ListNode* cur = begin;
        ListNode* next = NULL;
        while(cur != right)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        begin->next = right;
        if(left)
        {
            left->next = end;
        }
        else 
        {
            head = end;
        }
        return head;
    }
};