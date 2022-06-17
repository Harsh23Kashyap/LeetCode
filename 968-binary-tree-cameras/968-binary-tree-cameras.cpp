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
    
int dfs(TreeNode* root, int &count)
    {
        //leaf node needs camera so return -1;
        if(root->left==NULL and root->right==NULL)
        {
            //cout<<"leaf - "<<root->val<<endl;
            return -1;
        }
        int m=5;
        if(root->left!=NULL)
        m=dfs(root->left,count);
        int n=5;
        if(root->right!=NULL)
        n=dfs(root->right,count);
        //cout<<m<<","<<n<<endl;
        //My parent needs a camera
        if(m==-1 or n==-1)
        {
            //cout<<"My child didnt have camera. Putting camera - "<<root->val<<endl;
            count++;
            return 0;
        }
        // My child has covered me
        if(m==0 or n==0)
        {
            //cout<<"My child has covered me - "<<root->val<<endl;
            return 1;
        }
        
        // I am not covered. My parent needs. camera
        //cout<<"I am not covered. My parent needs camera - "<<root->val<<endl;
        return -1;
    }
    int minCameraCover(TreeNode* root) 
    {
        
        int count=0;
        int l=dfs(root,count);
        if(l==-1)
            count++;
        return count;
        
    }
};