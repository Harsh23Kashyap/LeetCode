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
    void inorder(TreeNode* root, string curr,string &ans)
    {
        if(root==NULL)
            return;
       curr=(char)(root->val+'a')+curr;
        if(root->left==NULL and root->right==NULL)
        {
            if(curr<ans)
                ans=curr;
            return;
        }
        inorder(root->left,curr,ans);
        inorder(root->right,curr,ans);
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans(87000,'z');
        inorder(root,"",ans);
        return ans;
        
    }
};