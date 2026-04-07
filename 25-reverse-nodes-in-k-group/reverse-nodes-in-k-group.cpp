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
ListNode* reverse(ListNode* head, int k){
        ListNode* curr=head;
        ListNode* nhead=curr;
        int c=0;
        while(nhead!=NULL and c<k){
            nhead=nhead->next;
            c++;
        }
        if(c<k)
            return curr;

        
        ListNode* prev=NULL; 
        while(curr!=nhead){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head->next=reverse(nhead,k);
        return prev;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* del=new ListNode(-1);
        del->next=head;
        return reverse(head,k);
        
    }   
};