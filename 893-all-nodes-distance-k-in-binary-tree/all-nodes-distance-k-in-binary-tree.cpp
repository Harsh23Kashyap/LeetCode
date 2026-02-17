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
TreeNode* targett;
int k;
    int pass(TreeNode* root, int found){
        if(root==NULL)
        return -1;

        if(root==targett){
            if(k==0){
            ans.push_back(root->val);
            return -1;
            }

            pass(root->left,1);
            pass(root->right,1);
            return 1;

        }
        else{
            if(found!=-1){
                if(found==k){
                    ans.push_back(root->val);
                }
                else{
                    pass(root->left,found+1);
                    pass(root->right,found+1);
                }
            }
            else{
                 int a= pass(root->left,-1);
                 int b= pass(root->right,-1);
                 if(a!=-1){
                    if(a==k){
                        ans.push_back(root->val);
                        
                    } 
                    else{
                    pass(root->right,a+1);
                    }
                    return 1+a;
                 }
                 if(b!=-1){
                    if(b==k){
                        ans.push_back(root->val);
                    } 
                    else{
                    pass(root->left,b+1);
                    }

                        return 1+b;
                 }
            }
        }

        return -1;



    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int ck) {
        k=ck;
        targett=target;
        pass(root,-1);
        return ans;
    }
};