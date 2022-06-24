/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* x=headA;
        ListNode* y=headB;
        
        int lA=0,lB=0;
        while(x)
        {
            lA++;
            x=x->next;
        }
        
        while(y)
        {
            lB++;
            y=y->next;
        }
        
        if(lA>=lB)
        {
            x=headA;
            y=headB;
        }
        else
        {
            x=headB;
            y=headA;
        }
        
        for(int i=0;i<abs(lA-lB);i++)
            x=x->next;
        
        while(x and y)
        {
            cout<<x->val<<" and "<<y->val<<endl;
            if(x==y)
                return x;
            x=x->next;
            y=y->next;
        }
        return NULL;
        
    }
};