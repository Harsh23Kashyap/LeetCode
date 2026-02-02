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
TreeNode* create(int i, int j, int len, vector<int>& preorder,unordered_map<int,int> &u){
    // cout<<i<<" "<<j<<" "<<len<<endl;
    if(i>=preorder.size())
        return NULL;
    
    if(j>len)
        return NULL;
    
    if(j==len)
        return new TreeNode(preorder[i]);

    
    TreeNode* n=new TreeNode(preorder[i]);
    // cout<<"Creating node "<<n->val<<endl;
    int ind=u[preorder[i]];
    // cout<<ind<<endl;
    int range=ind-j;
    n->left=create(i+1,j,ind-1,preorder,u);
    n->right=create(i+range+1,ind+1,len,preorder,u);

    return n;
    

    

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> u;
        for(int i=0;i<preorder.size();i++)
            u[inorder[i]]=i;

        return create(0,0,inorder.size(),preorder,u);

    }
};