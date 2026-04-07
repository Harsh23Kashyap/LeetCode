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
unordered_map<int, vector<TreeNode*>> u;

    void postorder(TreeNode* curr, TreeNode* par){
        if(curr==NULL)
        return;
        if(par!=NULL)
        u[curr->val].push_back(par);
        if(curr->left!=NULL)
        u[curr->val].push_back(curr->left);
         if(curr->right!=NULL)
        u[curr->val].push_back(curr->right);

        postorder(curr->left,curr);
        postorder(curr->right,curr);


    }
    int amountOfTime(TreeNode* root, int start) {
        postorder(root,NULL);

        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int c=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                for(auto ne:u[it]){
                    if(!vis.count(ne->val)){
                        vis.insert(ne->val);
                        q.push(ne->val);
                    }
                }
                
            }
            c++;
        }
        return c;
    }
};