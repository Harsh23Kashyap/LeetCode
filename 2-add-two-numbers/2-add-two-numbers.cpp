/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
         ListNode* res=new ListNode(0);
        
         ListNode* head=res;
        int sum=0,carry=0;
        while(l1 and l2)
        {
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* curr= new ListNode(sum);
            res->next=curr;
            res=curr;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* curr= new ListNode(sum);
            res->next=curr;
            res=curr;
            l1=l1->next;
        }
        while(l2)
        {
    
            sum=l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* curr= new ListNode(sum);
            res->next=curr;
            res=curr;
            l2=l2->next;
        }
        if(carry>0)
        {
            ListNode* curr= new ListNode(carry);
            res->next=curr;
            res=curr;
        }
            
        return head->next;
        
    }
};