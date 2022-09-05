/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*> q;
        
        q.push(root);
         vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                Node* t=q.front();
                temp.push_back(t->val);
                q.pop();
                for(int i=0;i<t->children.size();i++)
                    q.push(t->children[i]);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};