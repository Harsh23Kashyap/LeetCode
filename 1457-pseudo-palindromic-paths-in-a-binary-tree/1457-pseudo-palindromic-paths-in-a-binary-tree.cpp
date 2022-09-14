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
    
    void inorder(TreeNode* root,  vector<int> u, int &count)
    {
        if(root==NULL)
            return;
        
        u[root->val]++;
        //cout<<root->val<<" "<<u[root->val]<<endl;
        if(u[root->val]%2!=0)
            count++;
        else
            count--;
        if(root->left==NULL and root->right==NULL)
        {
           // cout<<" count "<<count<<endl;
            if(count<=1)
                ans++;
        }
        inorder(root->left,u,count);
        inorder(root->right,u,count);
        
        u[root->val]--;
          if(u[root->val]%2!=0)
            count++;
        else
            count--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> u(10,0);
        int count=0;
        inorder(root,u,count);
        return ans;
    }
};