/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(slow!=fast && slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow==fast;
    
        
    }
};
