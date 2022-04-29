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
   
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(!root)
            return;
        else
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    int minDiffInBST(TreeNode* root) 
    {
         vector<int> v;
        inorder(root,v);
        int m=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
            m=min(v[i+1]-v[i],m);
        return m;
        
    }
};