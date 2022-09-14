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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, int> m;
        m[0]++;
        
        int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
    void helper(TreeNode *p, long long cur, int sum, int &total, unordered_map<long long, int> &m) {
        if (!p) return;
        
        cur += p->val;
        if (m.find(cur - sum) != m.end()) total += m[cur - sum];
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;
    }
};