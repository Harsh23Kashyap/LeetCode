/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(original==NULL)
            return NULL;
        
        //cout<<cloned->val <<" and "<<original->val<<endl;
        if(target==original)
            return cloned;
        
        TreeNode* leftVal=getTargetCopy(original->left, cloned->left, target);
        if(leftVal!=NULL)
            return leftVal;
         return getTargetCopy(original->right, cloned->right, target);
        
    }
};