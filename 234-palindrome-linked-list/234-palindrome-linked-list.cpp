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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        int n=0;
        while(slow!=NULL)
        {
            slow=slow->next;
            n++;
        }
        slow=head;
        for(int i=0;i<n/2;i++)
        {
            slow=slow->next;
        }
        if(n%2!=0)
            slow=slow->next;
        
        ListNode* secondpart=reverse(slow);
        ListNode* temp=secondpart;
//         while(temp!=NULL)
//         {
//             cout<<temp->val;
//             temp=temp->next;
            
//         }
        while(head!=NULL and secondpart!=NULL)
        {
            if(head->val!=secondpart->val)
                return false;
            head=head->next;
            secondpart=secondpart->next;
        }
        return true;
    }
};