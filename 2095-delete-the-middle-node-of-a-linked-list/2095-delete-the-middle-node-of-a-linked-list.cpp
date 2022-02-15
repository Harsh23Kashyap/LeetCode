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
    ListNode* deleteMiddle(ListNode*&head) 
    {
        ListNode* temp=head;
        
        int n=0;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        n=(int)floor(n*1.0/2);
        if(n==0)
        {
            head=head->next;
            return head;
        }
            
            
            
        
        ListNode* prev=head;
        ListNode* curr=head;
        for(int i=0;i<n;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
        
    }
};