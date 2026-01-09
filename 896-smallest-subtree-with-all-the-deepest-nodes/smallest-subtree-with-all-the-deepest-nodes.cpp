class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {NULL, 0};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.second > R.second)
            return {L.first, L.second + 1};
        if (R.second > L.second)
            return {R.first, R.second + 1};

        // same depth → current node is LCA
        return {root, L.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
