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
class BSTIterator {
public:
    vector<int> v;
    int ind=-1;
    void Inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        Inorder(root->left);
        Inorder(root->right);
            
    }
    BSTIterator(TreeNode* root) 
    {
         Inorder(root);
        sort(v.begin(),v.end());
    }
    
    int next() 
    {
        ind++;
        return v[ind];
    }
    
    bool hasNext() 
    {
        return ind+1!=v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */