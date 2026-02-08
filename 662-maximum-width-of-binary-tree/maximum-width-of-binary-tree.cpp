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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int ans=0;
        q.push({root,1});
        while(!q.empty()){
            int sz=q.size();
            int sza=q.front().second;
            int last=sza;
            while(sz--){
                auto [it,ind]=q.front();
                q.pop();
                last=ind;
                if(it->left!=NULL)
                    q.push({it->left,2ll*ind-sza});
                if(it->right!=NULL)
                    q.push({it->right,2ll*ind+1-sza});
            }
            ans=max(ans,last-sza+1);
        }
        return ans;
    }
};