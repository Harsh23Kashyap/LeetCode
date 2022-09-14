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
    void inorder(TreeNode* root, long long val,long long &sum)
    {
        if(root==NULL)
            return;
        val=val*10+(root->val);
        if(root->left==NULL and root->right==NULL)
        {
            sum+=val;
            return;
        }
        inorder(root->left,val,sum);
        inorder(root->right,val,sum);
    }
    int sumNumbers(TreeNode* root) 
    {
        long long sum=0;
        inorder(root, 0, sum);
        return sum;
    }
};