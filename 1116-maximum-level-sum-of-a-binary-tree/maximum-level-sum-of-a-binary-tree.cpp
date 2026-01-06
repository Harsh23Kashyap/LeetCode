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
    int maxLevelSum(TreeNode* root) {
       int maxi=root->val;
       int lev=1,cl=1;
       queue<TreeNode*> q;
        q.push(root);
       while(!q.empty()){
        int cs=0;
        int sz=q.size();
        while(sz--){
            TreeNode* curr=q.front();
            cs+=curr->val;
            q.pop();

            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);

        }
       if(maxi<cs){
        maxi=cs;
        lev=cl;
       }
       cl++;
        // maxi=max(maxi,cs);
       }
       return lev;
    }
};