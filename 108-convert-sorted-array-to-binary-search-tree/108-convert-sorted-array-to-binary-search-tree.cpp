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
    TreeNode* pass(vector<int>& nums,int start,int end)
    {
        //cout<<"start - "<<start<<" end - "<<end<<endl;
        if(start>=end)
            return NULL;
        
        int mid=(start+end)/2;
        TreeNode* curr= new TreeNode();;
        cout<<nums[mid]<<endl;
        curr->val=nums[mid];
        curr->left=pass(nums,start,mid);
        curr->right=pass(nums,mid+1,end);
        return curr; 
        
            
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return pass(nums,0,nums.size());
        
    }
};