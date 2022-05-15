class Solution
{
public:
    vector<TreeNode *> tree;

    bool subTree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        if (root == NULL || subRoot == NULL)
            return false;

        return (root->val == subRoot->val &&
                subTree(root->left, subRoot->left) &&
                subTree(root->right, subRoot->right));
    }
 
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if(root==NULL) return false;
        if(subTree(root,subRoot)) return true;
        if(isSubtree(root->left,subRoot)) return true;
        if(isSubtree(root->right,subRoot)) return true;
        return false;
    }
};