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
    void inorder(TreeNode* root, vector<int>&v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> v;
        inorder( root, v);
        TreeNode* answer= balance(0,v.size()-1,v);
        return answer;
    }
    TreeNode* balance(int start, int end, vector<int> v)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* curr=new TreeNode(v[mid]);
        //cout<<curr->val<<" -"<<start<<","<<end<<endl;
        curr->left=balance(start, mid-1, v);
        curr->right=balance(mid+1, end, v);
        return curr;
    }
    
};