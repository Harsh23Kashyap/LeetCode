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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(!st.empty() or node!=NULL)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                TreeNode* curr=st.top()->right;
                if(curr!=NULL)
                    node=curr;
                else
                {
                    curr=st.top();
                    st.pop();
                    ans.push_back(curr->val);
                    while(!st.empty() and st.top()->right==curr)
                    {
                        curr=st.top();
                        st.pop();
                        ans.push_back(curr->val);
                    }
                        
                }
            }
        }
        return ans;
    }
};