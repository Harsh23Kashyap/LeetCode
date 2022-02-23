/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
            return root;
        
        if(root==p or root==q)
            return root;
        
        TreeNode* found1=lowestCommonAncestor(root->left, p,q) ;
        TreeNode* found2=lowestCommonAncestor(root->right, p,q) ;
        if(found1 and found2)
            return root;
        
        if(found1!=NULL)
            return found1;
        return found2;
        
    }
};