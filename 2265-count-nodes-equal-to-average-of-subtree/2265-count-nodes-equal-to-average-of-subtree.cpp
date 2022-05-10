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
    int count=0;
    pair<int,int> postorder(TreeNode* root)
    {
        if(!root)
            return {0,0};
        cout<<root->val<<endl;
        if(root->left==NULL and root->right==NULL)
        {
            count++;
            return {root->val,1};
        }
         
        pair<int,int> left=postorder(root->left);
        pair<int,int> right=postorder(root->right);
        int avg=(left.first+right.first+root->val)/(left.second+right.second+1);
        if(avg==root->val)
            count++;
        
        return {left.first+right.first+root->val,left.second+right.second+1};
        
    }
    int averageOfSubtree(TreeNode* root) 
    {
        postorder(root);
        return count;
    }
};