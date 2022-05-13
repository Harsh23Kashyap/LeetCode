/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return root;
        vector<vector<Node*>> v;
        queue<Node* > q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<Node*> temp;
            while(size--)
            {
                Node* curr=q.front();
                
                q.pop();
                
                temp.push_back(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            v.push_back(temp);
        }
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size()-1;j++)
            {
                v[i][j]->next=v[i][j+1];
            }
        }
        return root;
    }
};