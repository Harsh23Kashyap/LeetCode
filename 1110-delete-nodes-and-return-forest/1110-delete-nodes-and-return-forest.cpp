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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) 
    {
        unordered_set<int> s(del.begin(),del.end());
        vector<TreeNode*> ans;
        queue<pair<TreeNode*,bool>> q;
        if(s.find(root->val)!=s.end())
            q.push({root,true});
        else
            q.push({root,false});
         if(s.find(root->val)==s.end())
             ans.push_back(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr=q.front().first;
                bool remove=q.front().second;
                //cout<<"Node - "<<curr->val<<" "<<remove<<endl;
                q.pop();
                if(curr->left!=NULL)
                {
                    if(s.find(curr->left->val)!=s.end())
                    {
                        
                        q.push({curr->left,true});
                        curr->left=NULL;
                    }
                    else
                         q.push({curr->left,false});
                    
                    if(remove)
                        ans.push_back(curr->left);
                }
                if(curr->right!=NULL)
                {
                     if(s.find(curr->right->val)!=s.end())
                     {
                        q.push({curr->right,true});
                         curr->right=NULL;
                     }
                    else
                         q.push({curr->right,false});
                    
                    if(remove)
                        ans.push_back(curr->right);
                }
                if(remove)
                {
                    curr->left=NULL;
                    curr->right=NULL;
                }
                
            }
        }
        vector<TreeNode*> res;
        for(auto it:ans)
            if(it!=NULL)
                res.push_back(it);
        return res;
        
    }
};