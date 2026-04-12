/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "null,";
        queue<TreeNode*> q;
        q.push(root);
        string s="";
        while(!q.empty()){
            TreeNode* it=q.front();
            q.pop();
            
            if(it!=NULL){
                s+=to_string(it->val)+",";
                q.push(it->left);
                q.push(it->right);

            }
            else{
                s+="null,";
            }

        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        vector<string> ans;
        string curr="";
        for(int i=0;i<s.size();i++){
            if(s[i]==',')
            {
                ans.push_back(curr);
                curr="";
            }
            else
                curr=curr+s[i];

        }



        if(ans[0]=="null")
            return NULL;
        
        TreeNode* t=new TreeNode(stoi(ans[0]));
        queue<TreeNode*> q;
        q.push(t);
        int i=1;
        while(!q.empty() and i<ans.size()){
            TreeNode* curr=q.front();
            q.pop();
            if(i>=ans.size())
            continue;
            if(ans[i]=="null"){
                curr->left=NULL;
            }
            else{
                curr->left=new TreeNode(stoi(ans[i]));
                q.push(curr->left);
            }
            i++;
             if(i>=ans.size())
            continue;
            if(ans[i]=="null"){
                curr->right=NULL;
            }
            else{
                curr->right=new TreeNode(stoi(ans[i]));
                q.push(curr->right);
            }
            i++;

        }
        return t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));