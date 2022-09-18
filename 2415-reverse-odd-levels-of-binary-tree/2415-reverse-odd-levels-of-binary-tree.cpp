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
   
    void trav(TreeNode* root1,TreeNode* root2,int lev)
    {
        if(root1==NULL or root2==NULL)
            return ;
        if(lev%2!=0)
            swap(root1->val,root2->val);
        
        trav(root1->left,root2->right,lev+1);
         trav(root1->right,root2->left,lev+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
       trav(root->left,root->right,1);
        return root;
        
    }
    
};