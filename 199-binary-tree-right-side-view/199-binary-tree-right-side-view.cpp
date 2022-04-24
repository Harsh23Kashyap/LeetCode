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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        vector<pair<int,int>> temp;
        if(!root)
            return ans;
        q.push({root,1});
        while(!q.empty())
        {
            //cout<<"Hi"<<endl;
            TreeNode* curr=q.front().first;
            int lev=q.front().second;
            q.pop();
            //cout<<curr->val<<endl;
            temp.push_back({lev,curr->val});
            if(curr->left)
                q.push({curr->left,lev+1});
            if(curr->right)
                q.push({curr->right,lev+1});
            
        }
        
//         for(int i=0;i<temp.size();i++)
//             cout<<temp[i].first<<" "<<temp[i].second<<endl;
        
        
        for(int i=0;i<temp.size()-1;i++)
        {
            if(temp[i].first!=temp[i+1].first)
                ans.push_back(temp[i].second);
        }
        
        ans.push_back(temp[temp.size()-1].second);
        return ans;
        
    }
};