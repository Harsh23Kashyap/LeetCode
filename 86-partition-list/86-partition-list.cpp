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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL) return NULL;
        
        ListNode* small=new ListNode(head->val);
        ListNode* sh=small;
        ListNode* greater=new ListNode(head->val);
        ListNode* gh=greater;
        ListNode* temp=head->next;
        while(temp!=NULL)
        {
            cout<<temp->val<< " ";
            if(temp->val<x)
            {
                small->next=temp;
                small=small->next;
                
            }  
            else
            {
                 greater->next=temp;
                greater=greater->next;
            }
            temp=temp->next;
        }
        
        cout<<"runs";
        if(head->val<x)
            gh=gh->next;
        else
            sh=sh->next;
        
        greater->next=NULL;
        if(sh==NULL) return gh;
        small->next=gh;
        return sh;
        
    }
};