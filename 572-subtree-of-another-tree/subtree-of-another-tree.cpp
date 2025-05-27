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
bool pass(TreeNode* root, TreeNode* subtree){
      if(root==NULL and subtree==NULL)
        return true;
         if(root==NULL or subtree==NULL)
        return false;


        return root->val==subtree->val and pass(root->left,subtree->left) and pass(root->right,subtree->right) ;
}
    bool isSubtree(TreeNode* root, TreeNode* subtree) {
       if(root==NULL and subtree==NULL)
        return true;
         if(root==NULL or subtree==NULL)
        return false;
        return pass(root,subtree) or  isSubtree(root->left,subtree) or  isSubtree(root->right,subtree);
    }
};