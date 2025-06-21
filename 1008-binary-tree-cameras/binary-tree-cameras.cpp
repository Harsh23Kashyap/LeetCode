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
/*

if my child has camera it will return 1, and ill pass 0 saying I dont need camera

if my child doesnt have camera it will return 0, and ill pass 0 saying I dont need camera

*/
int c=0;
string dfs(TreeNode* root){
    if(root==NULL)
        return "";
    if(root->left==NULL and root->right==NULL)
        return "no camera";
    string m="",n="";
     if(root->left!=NULL)
     m=dfs(root->left);
     if(root->right!=NULL)
     n=dfs(root->right);
     cout<<root->val<<" "<<m<<" "<<n<<endl;
    //one of my child doesnt have camera
    if(m=="no camera" or n=="no camera")
    {
        //install camera for myself,
        c++;
        return "camera installed";
    }
    if(m=="camera installed" or n=="camera installed"){
        return "no camera need";
    }
    return "no camera";

}
    int minCameraCover(TreeNode* root) {
    if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL)
        return 1;

        if(dfs(root)=="no camera")
        c++;
        return c;
    }
};