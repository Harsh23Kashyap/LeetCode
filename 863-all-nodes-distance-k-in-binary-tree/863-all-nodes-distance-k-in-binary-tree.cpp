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
    void printKLevel(TreeNode* target,int K)
    {
        if(!target)
            return;
        if(K==0)
        {
            //cout<<target->val<<endl;
            ans.push_back(target->val);
            return;
        }
        printKLevel(target->left,K-1);
        printKLevel(target->right,K-1);
    }
    int printKthNode(TreeNode* root, TreeNode* target, int k) 
    {
        if(root==NULL)
            return -1;
        if(root==target)
        {
            printKLevel(target,k);
            return 0;
            
        }
        int DL=printKthNode(root->left,target,k);
        if(DL!=-1)
        {
            if(DL+1==k)
            {
                //cout<<root->val<<endl;
                ans.push_back(root->val);
            }
            else
            {
                printKLevel(root->right,k-2-DL);
                
            }
            return 1+DL;
        }
        int DR=printKthNode(root->right,target,k);
        if(DR!=-1)
        {
            if(DR+1==k)
            {
                //cout<<root->val<<endl;
                ans.push_back(root->val);
            }
            else
            {
                printKLevel(root->left,k-2-DR);
                
            }
            return 1+DR;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        printKthNode(root,target,k);
        return ans;
    }
};