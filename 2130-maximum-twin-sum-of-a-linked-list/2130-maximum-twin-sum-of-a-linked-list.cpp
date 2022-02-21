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
    ListNode* reverse(ListNode*&head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) 
    {
        if(head==NULL)
            return 0;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
         ListNode* shead=reverse(slow);
        int ms=0;
        while(head!=NULL and shead!=NULL)
        {
            ms=max(ms,head->val + shead->val);
            head=head->next;
            shead=shead->next;
        }
        return ms;
    }
};