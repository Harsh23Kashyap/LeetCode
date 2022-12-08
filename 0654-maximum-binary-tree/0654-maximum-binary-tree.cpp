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
    TreeNode* pass(vector<int> &nums,int l, int r)
    {
        if(l>r or r<0 or l>=nums.size())
            return NULL;
        if(l==r)
            return new TreeNode(nums[l]);
        int ind=l;
        for(int i=l+1;i<=r;i++)
        {
            if(nums[i]>nums[ind])
                ind=i;
        }
        TreeNode* temp=new TreeNode(nums[ind]);
        temp->left=pass(nums,l,ind-1);
        temp->right=pass(nums,ind+1,r);
        return temp;
            
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return pass(nums,0,nums.size()-1);
        
    }
};