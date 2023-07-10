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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l=INT_MAX/2;
        if(root->left!=NULL)
            l=minDepth(root->left);
        int r=INT_MAX/2;
        if(root->right!=NULL)
            r=minDepth(root->right);
        cout<<root->val<<" "<<l<<" "<<r<<endl;
        if(l==INT_MAX/2 and r==INT_MAX/2)
            return 1;
        else if (l==INT_MAX/2)
            return 1+r;
            else if (r==INT_MAX/2)
            return 1+l;
        return 1+min(l,r);
    }
};