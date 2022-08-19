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
    pair<int,int> postorder(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        
       pair<int,int> l=postorder(root->left);
        pair<int,int> r=postorder(root->right);
        
        //with root
        int with=root->val+l.second+r.second;
        
        //without root
        int wo=max(l.first,l.second)+max(r.first,r.second);
        
        return {with,wo};
        
        
    }
    int rob(TreeNode* root) 
    {
        
        pair<int,int> ans=postorder(root);
        return max(ans.first,ans.second);
    }
};