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
    ListNode* removeNthFromEnd(ListNode*&head, int n) 
    {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        int fromBeg=len-n;
         ListNode* curr=head;
        ListNode* prev=head;
        if(fromBeg==0)
        {
            head=head->next;
            return head;
        }
        for(int i=0;i<fromBeg;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
        
    }
};