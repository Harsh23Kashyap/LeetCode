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
    int post(TreeNode* root, int &a)
    {
        if(!root)
            return 0;
        int x=post(root->left,a);
        int y=post(root->right,a);
        
        a+=abs(x)+abs(y);
        return x+y+root->val-1;
    }
    int distributeCoins(TreeNode* root) 
    {
        int ans=0;
        int k=post(root,ans);
        return ans;
    }
};