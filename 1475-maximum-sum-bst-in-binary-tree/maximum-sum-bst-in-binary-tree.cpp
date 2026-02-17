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
int maxi=0;
vector<int> pass(TreeNode* root){
    if(root==NULL)
        return {1,INT_MAX, INT_MIN,0};
    
    auto lbst=pass(root->left);
    auto rbst=pass(root->right);

    if(lbst[0]==0 or rbst[0]==0)
        return {0,INT_MAX, INT_MIN,0};
    if(!(lbst[2]<root->val and rbst[1]>root->val))
        return  {0,INT_MAX, INT_MIN,0};
    if(lbst[2]>rbst[1])
        return  {0,INT_MAX, INT_MIN,0};
    maxi=max(maxi,lbst[3]+rbst[3]+root->val);
    int minVal = min(root->val, lbst[1]);
    int maxVal = max(root->val, rbst[2]);

    return {1,minVal,maxVal,lbst[3]+rbst[3]+root->val};

}
    int maxSumBST(TreeNode* root) {
         pass(root);
         return maxi;
    }
};