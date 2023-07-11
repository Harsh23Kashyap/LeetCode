/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void print(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
         print(root->left,k-1);
        print(root->right,k-1);
        
            
    }
    int kth(TreeNode* root,TreeNode* target,int k)
    {
        if(root==NULL)
        {
            return -1;
            
        }
        
        if(root==target)
        {
            print(root,k);
            return 0;
        }
        int DL=kth(root->left,target,k);
        if(DL!=-1)
        {
            if(DL+1==k)
            {
                ans.push_back(root->val);
                
            }
            else
            {
                print(root->right,k-2-DL);
            }
            return DL+1;
        }
        int DR=kth(root->right,target,k);
        if(DR!=-1)
        {
            if(DR+1==k)
            {
                ans.push_back(root->val);
                
            }
            else
            {
                print(root->left,k-2-DR);
            }
            return DR+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      
        kth(root,target,k);
       return ans;
    }
};