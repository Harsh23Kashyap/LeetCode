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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if(root==NULL)
            return {};
        queue<TreeNode*> q;
        bool ltr=true;
        q.push(root);
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            vector<int> temp;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            if(!ltr)
            reverse(temp.begin(),temp.end());
            ltr=!ltr;
            ans.push_back(temp);
        }
        
        return ans;
    }
};