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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sort(ListNode* head)
    {
       if(head==NULL)
           return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* curr=new TreeNode(slow->val);
        
        cout<<curr->val<<endl;
        if(prev!=NULL)
        {
            prev->next=NULL;
            curr->left=sort(head);
        }
        else
            curr->left=sort(prev);
        if(slow->next!=NULL)
        curr->right=sort(slow->next);
        return curr;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        return sort(head);
    }
};