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

        if(root == NULL)
            return "null,";

        queue<TreeNode*> q;

        q.push(root);

        string ans = to_string(root->val) + ",";

        while(!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // left
            if(curr->left == NULL) {

                ans += "null,";
            }
            else {

                ans += to_string(curr->left->val) + ",";

                q.push(curr->left);
            }

            // right
            if(curr->right == NULL) {

                ans += "null,";
            }
            else {

                ans += to_string(curr->right->val) + ",";

                q.push(curr->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> vals;

        string temp = "";

        // split by comma
        for(char c : data) {

            if(c == ',') {

                vals.push_back(temp);
                temp = "";
            }
            else {

                temp += c;
            }
        }

        // root null
        if(vals[0] == "null")
            return NULL;

        TreeNode* root =
            new TreeNode(stoi(vals[0]));

        queue<TreeNode*> q;

        q.push(root);

        int i = 1;

        while(!q.empty() && i < vals.size()) {

            TreeNode* curr = q.front();
            q.pop();

            // left
            if(vals[i] != "null") {

                curr->left =
                    new TreeNode(stoi(vals[i]));

                q.push(curr->left);
            }

            i++;

            // right
            if(i < vals.size() &&
               vals[i] != "null") {

                curr->right =
                    new TreeNode(stoi(vals[i]));

                q.push(curr->right);
            }

            i++;
        }

        return root;
    }
};