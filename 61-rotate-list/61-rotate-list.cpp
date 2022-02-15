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
    ListNode* rotateRight(ListNode*&head, int k) 
    {
        if(head==NULL)
            return head;
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        k=k%size;
        if(k==0)return head;
        temp=head;
        int initial=size-k;
        for(int i=1;i<initial;i++)
            temp=temp->next;
        
        //cout<<temp->val<<endl;
        ListNode* newhead=temp->next;
        
        
        //cout<<newhead->val<<endl;
        while(newhead->next!=NULL)
            newhead=newhead->next;
        
        newhead->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }
};