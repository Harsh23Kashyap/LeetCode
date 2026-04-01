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
        string res="";

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
    q.pop();
            
            if(it!=NULL){
res+= to_string(it->val)+",";
q.push(it->left);
q.push(it->right);
            }
            else{
                res+="null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> check;
string curr="";
        for(int i=0;i<data.size();i++){
            if(data[i]==',')
            {
                check.push_back(curr);
                curr="";
            }
            else{
                curr+=data[i];
            }
        }
    if(check[0]=="null")
    return NULL;

        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(check[0]));
        q.push(root);
        int i=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(check[i]!="null"){
                it->left=new TreeNode(stoi(check[i]));
                q.push(it->left);
            }
            i++;
           if(check[i]!="null"){
                it->right=new TreeNode(stoi(check[i]));
                q.push(it->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));