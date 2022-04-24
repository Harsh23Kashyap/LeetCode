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
//     vector<int> rightSideView(TreeNode* root) 
//     {
//         queue<pair<TreeNode*,int>> q;
//         vector<int> ans;
//         vector<pair<int,int>> temp;
//         if(!root)
//             return ans;
//         q.push({root,1});
//         while(!q.empty())
//         {
//             TreeNode* curr=q.front().first;
//             int lev=q.front().second;
//             q.pop();
//             temp.push_back({lev,curr->val});
//             if(curr->left)
//                 q.push({curr->left,lev+1});
//             if(curr->right)
//                 q.push({curr->right,lev+1});
            
//         }
        
        
//         for(int i=0;i<temp.size()-1;i++)
//         {
//             if(temp[i].first!=temp[i+1].first)
//                 ans.push_back(temp[i].second);
//         }
        
//         ans.push_back(temp[temp.size()-1].second);
//         return ans;
        
//     }
    int maxLevel=0;
    void reverseOrder(TreeNode* root, vector<int>& ans,int lev)
    {
        if(root==NULL)
            return;
        if(lev>maxLevel)
        {
            maxLevel=lev;
            ans.push_back(root->val);
        }
        reverseOrder(root->right,ans,lev+1);
        reverseOrder(root->left,ans,lev+1);
        
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        reverseOrder(root,ans,1);
        return ans;
    }
};