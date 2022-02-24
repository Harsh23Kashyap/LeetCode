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
//     ListNode* merge(ListNode* head) 
//     {
        
//     }
//     ListNode* getMiddle(ListNode* head)
//     {
//         ListNode* slow=head;
//         ListNode* fast=head;
//         while(fast->next!=NULL and fast->next->next!=NULL)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* sortList(ListNode* head) 
//     {
//         merge(head);
        
//     }
    ListNode* sortList(ListNode*&head) 
    {
       vector<int> v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            temp->val=v[i++];
            temp=temp->next;
        }
        return head;
        
    }
};