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
        ListNode* temp = head; 
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }
        
        // Step 2: reverse first k nodes
        ListNode* newHead = reverseK(head, k);
        
        // Step 3: recursion for remaining
        head->next = reverseKGroup(temp, k);
        
        return newHead;
    }
};