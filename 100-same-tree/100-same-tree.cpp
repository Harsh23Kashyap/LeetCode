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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL and q==NULL)
            return true;
        if(p==NULL)
            return false;
        if(q==NULL)
            return false;
        
        if(p->val!=q->val)
            return false;
        bool l=isSameTree(p->left,q->left);
        if(!l)
            return false;
        bool r=isSameTree(p->right,q->right);
        if(!r)
            return false;
        return true;
        
    }
};