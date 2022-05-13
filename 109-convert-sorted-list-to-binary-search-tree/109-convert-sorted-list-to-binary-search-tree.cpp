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
    TreeNode* sort(ListNode* head, ListNode* end)
    {
        if(head==NULL and end==NULL)
            return NULL;
        if(head->next==end)
        {
            TreeNode* curr=new TreeNode(head->val);
            return curr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast->next!=end and fast->next->next!=end)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* curr=new TreeNode(slow->val);
        
        cout<<curr->val<<endl;
        if(prev!=NULL)
        curr->left=sort(head, slow);
        if(slow->next!=NULL)
        curr->right=sort(slow->next,end);
        
        // cout<<"Parent"<<endl;
        // cout<<curr->val<<endl;
        // if(curr->left)
        //     cout<<"Left child "<<curr->left->val<<endl;
        // else
        //     cout<<"Left child - NULL"<<endl;
        // if(curr->right)
        //     cout<<"Right child "<<curr->right->val<<endl;
        // else
        //     cout<<"Right child - NULL"<<endl;
        return curr;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        return sort(head,NULL);
    }
};