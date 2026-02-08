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
    bool check(TreeNode* root, long mini, long maxi)
    {
        if(root==NULL)
            return true;
        if(root->val<=mini or root->val>=maxi)
            return false;
        
        if(!check(root->left, mini,root->val) or !check(root->right,root->val,maxi))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) 
    {
        long mini=long(INT_MIN)-1,maxi=long(INT_MAX)+1;
        return check(root,mini,maxi);
        
    }
};