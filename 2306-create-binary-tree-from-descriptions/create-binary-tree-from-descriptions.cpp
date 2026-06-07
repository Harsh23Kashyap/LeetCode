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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> ptc;
         unordered_map<TreeNode*,TreeNode*> ctp;
        TreeNode* curr=NULL;
         for(auto it:descriptions){
            if(ptc.find(it[0])==ptc.end()){
                TreeNode* a1=new TreeNode(it[0]);
                ptc[it[0]]=a1;
            }
            TreeNode* a1=ptc[it[0]];
            if(ptc.find(it[1])==ptc.end()){
                TreeNode* a2=new TreeNode(it[1]);
                ptc[it[1]]=a2;
            }
            TreeNode* a2=ptc[it[1]];

            if(it[2]==1)
                a1->left=a2;
            else
                a1->right=a2;

            ctp[a2]=a1;
            curr=a1;
            
         }

         while(ctp.find(curr)!=ctp.end()){
            curr=ctp[curr];
         }
         return curr;

         

    }
};