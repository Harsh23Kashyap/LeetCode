class Solution {
public:
    long long ts = 0;
    long long mp = 0;
    int mod = 1e9 + 7;

    void pass(TreeNode* root) {
        if (!root) return;
        ts += root->val;
        pass(root->left);
        pass(root->right);
    }

    long long find(TreeNode* root) {
        if (!root) return 0;

        long long lval = find(root->left);
        long long rval = find(root->right);

        long long cs = lval + rval + root->val;
        long long rs = ts - cs;

        mp = max(mp, cs * rs);

        return cs;
    }

    int maxProduct(TreeNode* root) {
        pass(root);
        find(root);
        return mp % mod;
    }
};
