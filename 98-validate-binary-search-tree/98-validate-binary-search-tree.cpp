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
    bool BST(TreeNode* root, long minVal,long maxVal)
    {
        if(!root)
            return true;
        if(root->val>minVal and root->val<maxVal and BST(root->left,minVal,root->val) and BST(root->right,root->val,maxVal))
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        return BST(root,LLONG_MIN	,LLONG_MAX	);
        
    }
};