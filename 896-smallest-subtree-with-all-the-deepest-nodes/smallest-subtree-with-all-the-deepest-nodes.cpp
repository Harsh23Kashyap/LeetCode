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
    pair<int, TreeNode*> pass(TreeNode* root){
        if(root==NULL)
            return {0,NULL};
        
        if(root->left==NULL and root->right==NULL)
            return {1, root};

        auto [sl,le]=pass(root->left);
        auto [sr,re]=pass(root->right);

        if(sl==sr){
            return {1+sl,root};
        }
        else if(sl>sr){
            return {1+sl,le};
        }
        return {1+sr,re};
        

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto it=pass(root);
        return it.second;
    }
};