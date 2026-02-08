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
map<int,int> u;
    void pass(TreeNode* root, int leb){
        if(root==NULL)
        return;

        if(u.find(leb)==u.end())
        u[leb]=root->val;

        pass(root->right,leb+1);
         pass(root->left,leb+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        

        pass(root,0);

        for(auto it:u){
            ans.push_back(it.second);
        }
        return ans;
    }
};