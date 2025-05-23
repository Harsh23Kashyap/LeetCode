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
pair<int,int> ans(TreeNode* root){
    if(root==NULL)
    return {0,0};
    auto a=ans(root->left);
    auto b=ans(root->right);
    // if(parentchor){
    // int c= a+b;
    // }
    // int mainchor=root->val+ans(root->left,true)+ans(root->right,true);
    return {root->val+a.second+b.second,max(a.first,a.second)+max(b.second,b.first)};
}
    int rob(TreeNode* root) {
       auto it= ans(root);
        return max(it.first,it.second);
       //Ill search
    }
};