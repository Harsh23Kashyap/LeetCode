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
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int ans=root->val;
        while(!q.empty())
        {
            int sz=q.size();
            bool first=false;
            while(sz--)
            {
                TreeNode* curr=q.front();
                if(!first)
                {
                    first=true;
                    ans=curr->val;
                }
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                    
                if(curr->right!=NULL)
                     q.push(curr->right);
            }
        }
        
        return ans;
        
    }
};