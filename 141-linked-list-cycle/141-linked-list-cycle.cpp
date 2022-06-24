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
        if(head==NULL or head->next==NULL)
            return false;
        ListNode *slow=head,*fast=head->next;
        while(fast->next and fast->next->next)
        {
            if(slow==fast)
                return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
        
    }
};