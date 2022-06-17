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
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b)
    {
        if(a.first<b.first)
            return true;
        else if(a.first==b.first)
        {
            return a.second<=b.second;
        }
        return false;
    }
    void verticalOrder(TreeNode* root, map<int,vector<pair<int,int>>> &m, int d,int lev)
    {
        if(!root)
            return;
        
        m[d].push_back({lev,root->val});
        
        verticalOrder(root->left,m,d-1,lev+1);
        verticalOrder(root->right,m,d+1,lev+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        
        map<int,vector<pair<int,int>>> m;
        verticalOrder(root,m,0,0);
         vector<vector<int>> ans;
        
        for(auto it:m)
        {
            vector<pair<int,int>> temp=it.second;
            
            vector<int> res;
            sort(temp.begin(),temp.end(),cmp);
            for(int i=0;i<temp.size();i++)
                res.push_back(temp[i].second);
            ans.push_back(res);
        }
        
        return ans;
        
    }
};