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
    int getDecimalValue(ListNode* head) 
    {
        long long ans=0;
        //int power=0;
        int n=0;
        ListNode* temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        while(head)
        {
            ans+=pow(2,--n)*head->val;
            head=head->next;
        }
        return ans;
        
    }
};