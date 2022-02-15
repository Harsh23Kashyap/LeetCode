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
    ListNode* swapNodes(ListNode*&head, int k) 
    {
         ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        int fromBeg=len-k;
         ListNode* curr=head;
        ListNode* prev=head;
        for(int i=0;i<fromBeg;i++)
            curr=curr->next;
        for(int i=1;i<k;i++)
            prev=prev->next;
        int t=prev->val;
        prev->val=curr->val;
        curr->val=t;
        //swap(&prev->val,&curr->val);
        return head;
        
        
    }
};