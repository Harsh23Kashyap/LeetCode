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
    
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;
        
        TreeNode* rightTree=root->right;
        TreeNode* leftTree=root->left;
        
        root->left=NULL;
        flatten(leftTree);
        flatten(rightTree);
        
        root->right=leftTree;
        TreeNode* bottom=root;
        while(bottom->right!=NULL)
        {
            cout<<bottom->val<<" ";
            bottom=bottom->right;
        }
        bottom->right=rightTree;
        
        
    }
};