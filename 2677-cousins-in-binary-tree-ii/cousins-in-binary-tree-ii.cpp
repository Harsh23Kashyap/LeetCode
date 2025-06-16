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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> u;

        queue<TreeNode*> q;

        q.push(root);
        int c=0;
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            while(sz--){

                TreeNode* curr=q.front();
                q.pop();

                sum+=curr->val;

                if(curr->left!=NULL)
                {
                    q.push(curr->left);

                }

                if(curr->right!=NULL)
                {
                    q.push(curr->right);

                }


            }
            c++;

            u[c]=sum;
        }
        root->val=0;
        q.push(root);
        c=1;
        while(!q.empty()){
            int sz=q.size();
            cout<<c<<endl;
            while(sz--){

                TreeNode* curr=q.front();
                q.pop();
                int tot=0;
                if(curr->left!=NULL)
                {
                    tot+=curr->left->val;
                    q.push(curr->left);

                }

                if(curr->right!=NULL)
                {
                    tot+=curr->right->val;
                    q.push(curr->right);

                }
                
                int x=u[c+1];
                cout<<tot<<" "<<x<<endl;
                 if(curr->left!=NULL)
                {
                   curr->left->val=x-tot;
                }

                if(curr->right!=NULL)
                {
                    curr->right->val=x-tot;
                }



            }
            c++;

        }

        return root;


    }
};