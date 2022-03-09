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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL or head->next==NULL)
            return head;
        
       ListNode* newHead=new ListNode(500,head);
        ListNode* special=newHead;
        while(head!=NULL)
        {
            if(head->next!=NULL and head->val == head->next->val)
            {
                while(head->next!=NULL and head->val==head->next->val)
                {
                    //cout<<head->val;
                    head=head->next;
                }
            }
            else
            {
                newHead->next=head;
                newHead=newHead->next;
            }
            head=head->next;
        }
        newHead->next=head;
        return special->next;
    }
};