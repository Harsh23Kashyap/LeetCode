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
    void inorder(TreeNode* root, set<int>& s)
    {
        if(root==NULL)
            return;
            s.insert(root->val);
            inorder(root->left, s);
            inorder(root->right, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) 
    {
        int k=2;
         set<int> s;
        int smal=-1;
        inorder(root, s);
        for(auto it:s)
        {
            k--;
            if(k==0)
            {
                smal=it;
                break;
            }
        }
        return smal;
    }
};