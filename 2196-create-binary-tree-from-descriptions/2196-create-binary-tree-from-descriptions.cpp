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
    TreeNode* createBinaryTree(vector<vector<int>>& des) 
    {
        unordered_map<int,vector<int>> u;
        unordered_set<int> child;
        for(auto it:des)
        {
            child.insert(it[1]);
            u[it[0]].push_back(it[1]);
            u[it[0]].push_back(it[2]);
        }
        int parent=-1;
        for(auto it:u)
        {
            if(child.find(it.first)==child.end())
            {
                parent=it.first;
                break;
            }
        }
        
        TreeNode* root=new TreeNode(parent);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* temp=q.front();
                vector<int> child=u[q.front()->val];
                q.pop();
                
                int len=child.size();
                //cout<<temp->val<<" "<<len<<endl;
               if(len==0)
                   continue;
                if(len==2)
                {
                    int l=child[1];
                    if(l==1)
                    {
                        temp->left=new TreeNode(child[0]);
                        q.push(temp->left);
                        
                    }
                    else
                    {
                        temp->right=new TreeNode(child[0]);
                        q.push( temp->right);
                        
                    }
                    
                }
                else
                {
                    int l=child[1];
                    if(l==1)
                    {
                        temp->left=new TreeNode(child[0]);
                        q.push(temp->left);
                        temp->right=new TreeNode(child[2]);
                        q.push(temp->right);
                        
                    }
                    else
                    {
                        temp->right=new TreeNode(child[0]);
                       
                        temp->left=new TreeNode(child[2]);
                        q.push(temp->left);
                         q.push( temp->right);
                        
                    }
                }
                    
            }
        }
        return root;
        
        
    }
};