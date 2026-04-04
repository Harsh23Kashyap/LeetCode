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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> u(nums.begin(),nums.end());

        int c=0;
        ListNode* curr=head;
        while(curr!=NULL){
            if(u.count(curr->val))
            {
                while(curr!=NULL and u.count(curr->val)) 
                    curr=curr->next;
             
                c++;
            }
            else
                curr=curr->next;
        }
        return c;
    }
};

