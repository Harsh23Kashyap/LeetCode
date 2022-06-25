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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL or head->next==NULL)
          return NULL;
       
        ListNode* slow=head;
        ListNode* fast=head->next;
        bool cycle=false;
        while(fast!=NULL and fast->next!=NULL)
        {
            if(fast==slow)
            {
                cycle=true;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!cycle)
            return NULL;
        slow=slow->next;
        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};

//         2  3 -9 
// 5 *8 4 
//         -6  1