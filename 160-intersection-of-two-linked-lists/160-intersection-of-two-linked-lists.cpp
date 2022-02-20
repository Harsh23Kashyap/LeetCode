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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL or headB ==NULL)
            return NULL;
        while(headA)
        {
            ListNode* temp=headB;
            while(temp)
            {
                if(headA==temp)
                    return headA;
                temp=temp->next;
            }
            
            headA=headA->next;
        }
        return NULL;
    }
};