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
    long long tot=0,res=0;
    void summation(TreeNode* root)
    {
        if(!root)
            return;
        
        tot+=root->val;
        summation(root->left);
        summation(root->right);
    }
    int seperate(TreeNode* root)
    {
         if(!root)
            return 0;
        
        long long le=seperate(root->left),ri=seperate(root->right);
        
        res=max(res,max((tot-le)*le,(tot-ri)*ri));
        return le+ri+root->val;
        
    }
    int maxProduct(TreeNode* root) 
    {
        int m=1e9+7;
        summation(root);
        cout<<tot<<endl;
        long long k=seperate(root);
        return res%m;
        
    }
};