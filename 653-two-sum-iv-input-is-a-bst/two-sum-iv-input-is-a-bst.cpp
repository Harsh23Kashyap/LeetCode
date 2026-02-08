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
unordered_set<int> u;
bool res(TreeNode* root, int k){
    if(root==NULL)
    return false;

    if(res(root->left,k) or res(root->right,k))
    return true;

    if(u.find(k-(root->val))!=u.end())
    return true;

    u.insert(root->val);

    return false;
}
    bool findTarget(TreeNode* root, int k) {
        return res(root,k);
    }
};