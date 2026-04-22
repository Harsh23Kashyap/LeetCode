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
    pair<int,int> solve(TreeNode* root) {
        if (!root) 
            return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int rob = root->val + left.second + right.second;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};