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
class FindElements {
public:
    TreeNode* currroot;
    unordered_set<int> u;
    void pass(TreeNode* &root, int curr){
        if(root!=NULL)
        {
            root->val=0;
        }
        root->val=curr;
        u.insert(curr);
        if(root->left!=NULL)
            pass(root->left, 2*curr+1);
        if(root->right!=NULL)
            pass(root->right, 2*curr+2);
    }
    FindElements(TreeNode* root) {
        currroot=root;
        if(root->val==-1){
            pass(root, 0);
        }

    }

    bool find(int target) {
        return u.find(target)!=u.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */