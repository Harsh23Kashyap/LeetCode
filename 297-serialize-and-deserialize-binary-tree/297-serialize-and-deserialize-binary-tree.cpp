/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <iostream>
#include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s="";
        if(root==NULL)
            return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it!=NULL)
            s+=" "+to_string(it->val);
            else
            {
                s+=" #";
                continue;
            }
            if(it->left!=NULL)
                q.push(it->left);
            else
                q.push(NULL);
            if(it->right!=NULL)
                q.push(it->right);
            else
                q.push(NULL);
                
        }
        // cout<<s<<endl;
        return s.substr(1);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        s>>str;
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            //left
            s>>str;
            if(str=="#")
            {
                temp->left=NULL;
            }
            else
            {
                temp->left=new TreeNode(stoi(str));
                q.push(temp->left);
            }
            
             s>>str;
            if(str=="#")
            {
                temp->right=NULL;
            }
            else
            {
                temp->right=new TreeNode(stoi(str));
                q.push(temp->right);
            }
            
        }
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));