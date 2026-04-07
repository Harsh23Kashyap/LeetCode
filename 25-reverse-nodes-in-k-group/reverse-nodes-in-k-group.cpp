class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        cout << "\n=== New call to reverse ===\n";

        ListNode* curr = head;
        ListNode* nhead = curr;
        int c = 0;

        cout << "Counting nodes from current head...\n";
        while(nhead != NULL and c<k){
            cout << nhead->val << " -> ";
            nhead = nhead->next;
            c++;
        }
        cout << "NULL\n";
        cout << "Total nodes count = " << c << "\n";

        if(c < k){
            cout << "Less than k (" << k << "), returning head as-is\n";
            return curr;
        }

        cout << "Reversing first (" << k << "), nodes...\n";

        ListNode* prev = NULL; 
        curr = head;
        int step = 0;

        // ⚠️ Note: your condition uses nhead (currently NULL)
        while(curr != nhead){
            ListNode* nex = curr->next;

            cout << "Step " << step++ << ": reversing node " << curr->val << "\n";

            curr->next = prev;
            prev = curr;
            curr = nex;

            if(curr == NULL){
                cout << "Reached end during reversal\n";
            }
        }

        cout << "Finished reversing segment. New head = " << (prev ? prev->val : -1) << "\n";
        cout << "Old head (now tail) = " << head->val << "\n";

        cout << "Recursing for next segment...\n";
        head->next = reverse(nhead, k);

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        cout << "Starting reverseKGroup with k = " << k << "\n";

        ListNode* del = new ListNode(-1);
        del->next = head;

        return reverse(head, k);
    }   
};