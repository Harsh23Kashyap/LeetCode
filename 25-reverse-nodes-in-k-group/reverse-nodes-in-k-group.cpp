class Solution {
public:
    
    // reverse k nodes and return new head
    ListNode* reverseK(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (k--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev; // new head after reverse
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       
       if(head==NULL)
        return NULL;

        int count=0;
        ListNode* temp=head;
        while(count<k){
            count++;
            if(temp==NULL)
                return head;
            temp=temp->next;

        }

        ListNode* ret=reverseK(head,k);
        head->next=reverseKGroup(temp,k);
        return ret;


    }
};