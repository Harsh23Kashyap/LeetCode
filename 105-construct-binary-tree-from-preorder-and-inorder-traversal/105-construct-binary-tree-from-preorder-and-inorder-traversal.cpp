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
    int pointer=0;
     TreeNode* pass(vector<int>& preorder, vector<int>& inorder, int start, int end)
     {
         if(start>=end )
             return NULL;
         int curr=preorder[pointer++];
         int i;
         for(i=start;i<=end;i++)
         {
             if(inorder[i]==curr)
                 break;
         }
         
         TreeNode* present= new TreeNode();
         present->val=curr;
         present->left=pass(preorder,inorder,start,i);
         present->right=pass(preorder,inorder,i+1,end);
         return present;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return pass(preorder,inorder,0,inorder.size());
        
    }
};