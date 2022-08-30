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
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
       queue<TreeNode*> q;
       q.push(root);
        TreeNode* px=NULL;
        TreeNode* py=NULL;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL)
                {
                    if(curr->left->val==x)
                        px=curr;
                     if(curr->left->val==y)
                        py=curr;
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    if(curr->right->val==x)
                        px=curr;
                     if(curr->right->val==y)
                        py=curr;
                    q.push(curr->right);
                }
            }
            if(px!=NULL and py!=NULL and px==py)
                return false;
            if(px!=NULL and py!=NULL and px!=py)
                return true;
            if(px!=NULL and py==NULL)
                return false;
            if(px==NULL and py!=NULL )
                return false;
        }
        return false;
        
    }
};