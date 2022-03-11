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
    ListNode* reverse(ListNode*&head,ListNode*& end)
    {
        ListNode* curr=head;
        ListNode* temp=curr;
        ListNode* prev=NULL;
        ListNode* endNext=end->next;
        // cout<<endNext->val<<endl;
        while(curr!=endNext and curr!=NULL)
        {
            // cout<<curr->val;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        head->next=endNext;
        //cout<<"\n"<<head->val<<endl;
        // cout<<prev->val<<endl;
        head=prev;
        return head;
    }
    ListNode* reverseBetween(ListNode*&head, int left, int right) 
    {
        if(head==NULL or head->next==NULL)
            return head;
        if(left==right)
            return head;
        ListNode* start=head;
        ListNode* end=head;
        
        for(int i=1;i<left-1;i++)
            start=start->next;
         cout<<start->val<<endl;
        
        for(int i=1;i<right;i++)
            end=end->next;
         cout<<end->val<<endl;
        if(left==1)
            head=reverse(start,end);
        else
        {
            cout<<"runs"<<endl;
            start->next=reverse(start->next,end);
        }
        return head;
        
            
        
    }
};