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
int sum=0;
    void pass(string res){
        int a=0;
        for(int i=0;i<res.size();i++){
            a=(a<<1)|((res[i]-'0'));
        }
        sum+= a;
    }
    void dfs(TreeNode* r, string res){
        if(r==NULL)
        return;
        res=res+to_string(r->val);
        if(r->left==NULL and r->right==NULL)
            pass(res);
        
        dfs(r->left, res);
        dfs(r->right, res);
    }
    int sumRootToLeaf(TreeNode* root) {
         dfs(root,"");
         return sum;
    }
};