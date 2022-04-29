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
    bool ans(TreeNode* root,int value)
    {
        if(root->val==value)
        {
            bool left=true,right=true;
            if(root->left!=NULL)
                left=ans(root->left,value);
            if(root->right!=NULL)
                right=ans(root->right,value);
            return left and right;
        }
        return false;
    }
    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        int value=root->val;
        return ans(root,value);
        
    }
};