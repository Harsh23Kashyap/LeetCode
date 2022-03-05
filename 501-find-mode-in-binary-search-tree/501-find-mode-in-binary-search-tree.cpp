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
    void inorder(TreeNode* root, unordered_map<int,int>& u)
    {
        if(root==NULL)
            return;
            u[root->val]++;
            inorder(root->left, u);
            inorder(root->right, u);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> u;
        inorder(root,u);
        
        vector<int> v;
        int m=INT_MIN;
        for(auto it:u)
        {
            m=max(it.second,m);
        }
        for(auto it:u)
        {
            if(it.second==m)
                v.push_back(it.first);
        }
        return v;
        
        
        
    }
};