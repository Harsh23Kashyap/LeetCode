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
    int pointer;
    TreeNode* pass(vector<int>& inorder, vector<int>& postorder, int s, int e)
    {
        if(s>=e)
            return NULL;
        TreeNode* curr=new TreeNode();
        int value=postorder[pointer--];
        int i;
        for(i=s;i<=e;i++)
        {
            if(inorder[i]==value)
                break;
        }
        
        curr->val=value;
        curr->right=pass(inorder,postorder,i+1,e);
        curr->left=pass(inorder,postorder,s,i);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        pointer=postorder.size()-1;
        return pass(inorder,postorder,0,postorder.size());
        
    }
};