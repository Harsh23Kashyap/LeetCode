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
int maxSum=0;

    tuple<bool, int, int, int> dfs(TreeNode* root) {
        if (!root) {
            // Empty tree is a valid BST
            return {true, INT_MAX, INT_MIN, 0};
        }

        auto [lBST, lMin, lMax, lSum] = dfs(root->left);
        auto [rBST, rMin, rMax, rSum] = dfs(root->right);

        if (lBST && rBST && root->val > lMax && root->val < rMin) {
            int currSum = root->val + lSum + rSum;
            maxSum = max(maxSum, currSum);
            return {true, min(root->val, lMin), max(root->val, rMax), currSum};
        }

        // Return false BST with dummy values
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};