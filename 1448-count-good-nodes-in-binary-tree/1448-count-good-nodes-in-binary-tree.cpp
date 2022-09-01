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
    int ans=0;
    void order(TreeNode* root, int maxi)
    {
        if(root==NULL)
            return;
        if(root->val>=maxi)
        {
            //cout<<root->val<<" "<<maxi<<endl;
            ans++;
        }
        order(root->left,max(maxi,root->val));
        order(root->right,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) 
    {
        order(root,INT_MIN);
        return ans;
    }
};