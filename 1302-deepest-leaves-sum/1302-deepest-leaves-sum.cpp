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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    void summation(TreeNode* root, int depth)
    {
        if(root==NULL)
            return;
        if(depth==1)
            sum+=root->val;
        summation(root->left,depth-1);
         summation(root->right,depth-1);
    }
public:
    int sum=0;
    
    int deepestLeavesSum(TreeNode* root) 
    {
        int depth=maxDepth(root);
        summation(root,depth);
        return sum;
    }
};