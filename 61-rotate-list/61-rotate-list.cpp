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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL or k==0)
            return head;
        ListNode* slow=head;
        int n=0;
        while(slow)
        {
            n++;
            slow=slow->next;
        }
        
        if(k%n==0)
            return head;
        k=k%n;
        int move=n-k-1;
        slow=head;
        while(move--)
            slow=slow->next;
        
        ListNode* newh=slow->next;
        ListNode* temp=newh;
        slow->next=NULL;
        
        while(newh->next!=NULL)
            newh=newh->next;
        newh->next=head;
        return temp;
    }
};