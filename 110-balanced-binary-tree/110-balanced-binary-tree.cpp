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
    int height(TreeNode* root,set<bool>& ans)
    {
        if(!root)
            return 0;
        
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        // cout<<"Left - "<<lh<<endl;
        // cout<<"Right - "<<rh<<endl;
        if(abs(lh-rh)>1)
            ans.insert(false);
        else
            ans.insert(true);
        
        return max(lh,rh)+1;
            
    }
    bool isBalanced(TreeNode* root) 
    {
        set<bool> ans;
        if(root==NULL)
            return true;
       
        int m= height(root,ans);
        for(auto i:ans)
        {
            if(i==false)
                return false;
        }
        return true;
    }
};