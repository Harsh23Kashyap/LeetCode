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
    void view(TreeNode* tree, vector<int>& v)
    {
        if(tree==NULL)
            return;
        v.push_back(tree->val);
        view(tree->left,v);
        view(tree->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> v;
        view(root1,v);
        view(root2,v);
        sort(v.begin(),v.end());
        return v;
        
    }
};