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
    int maxDepth(Node* root) 
    {
        if(!root)
            return 0;
        queue<Node*> q;
        q.push(root);
        int k=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node* t=q.front();
                q.pop();
                vector<Node*> child=t->children;
                for(int i=0;i<child.size();i++)
                    q.push(child[i]);
            }
            k++;
        }
        return k;
        
    }
};