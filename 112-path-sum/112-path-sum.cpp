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
    bool correct=false;
    void path(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
            return;
        if(root!=NULL and root->left == NULL and root->right==NULL)
        {
            if(targetSum-root->val==0)
                correct=true;
            return;
        }
        if(correct==false)
        {
            path(root->left,targetSum-root->val);
            path(root->right,targetSum-root->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        path(root,targetSum);
        return correct;
    }
};