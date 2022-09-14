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
    void inorder(vector<vector<int>>& ans, vector<int> temp, TreeNode* root, int target)
    {
        if(root==NULL)
            return ;
        
        temp.push_back(root->val);
        target-=root->val;
        if(root->left==NULL and root->right==NULL)
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        inorder(ans,temp,root->left,target);
        inorder(ans,temp,root->right, target);
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
         inorder(ans,temp,root,targetSum);
        return ans;
        
    }
};