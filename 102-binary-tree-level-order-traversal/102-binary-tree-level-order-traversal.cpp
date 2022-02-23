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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<pair<TreeNode*,int>> q;
        queue<pair<TreeNode*,int>> ans;
        q.push(make_pair(root,1));
        ans.push(make_pair(root,1));
        while(!q.empty())
        {
            TreeNode* curr=(q.front()).first;
            int lev=(q.front()).second;
            
            q.pop();
            if(curr->left!=NULL)
            {
                q.push(make_pair(curr->left,lev+1));
                ans.push(make_pair(curr->left,lev+1));
            }
            if(curr->right!=NULL)
            {
            q.push(make_pair(curr->right,lev+1));
            
            ans.push(make_pair(curr->right,lev+1));
            }
            
        }
        
        TreeNode* res=new TreeNode(INT_MAX);
        vector<int> temp;
        int prev=1;
        ans.push(make_pair(res,INT_MAX));
        while(!ans.empty())
        {
            
            TreeNode* curr=(ans.front()).first;
           
            int lev=(ans.front()).second;
             cout<<curr->val<<" - "<<lev<< endl;
            ans.pop();
            if(lev==prev)
            {
                    temp.push_back(curr->val);
               prev=lev;
            }
            else
            {
                result.push_back(temp);
                temp.clear();
                temp.push_back(curr->val);
                prev=lev;
            }
            
        }
        return result;
        
    }
};