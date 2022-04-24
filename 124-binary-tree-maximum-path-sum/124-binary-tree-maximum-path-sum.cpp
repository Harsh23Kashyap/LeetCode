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
    int maxSum=INT_MIN;
    int path(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int op1=root->val;
        int lh=max(0,path(root->left));
        int rh=max(0,path(root->right));
        int op2=root->val+lh;
        int op3=root->val+rh;
        int op4=root->val+lh+rh;
        int b= max(op1,max(op2,max(op3,op4)));
        //cout<<b<<endl;
        maxSum=max(b,maxSum);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) 
    {
        int t= path(root);
        return max(maxSum,t);
        
    }
};