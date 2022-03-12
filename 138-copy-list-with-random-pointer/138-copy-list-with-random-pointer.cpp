/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (head==NULL)
            return NULL;
        unordered_map<Node*,Node*> u;
        
        Node* curr=head;
        while(curr)
        {
            Node* temp=new Node(curr->val);
            u[curr]=temp;
            curr=curr->next;
        }
        
        
        for(auto i:u)
        {
            Node* original=i.first;
            Node* created=i.second;
            
            if(original->next==NULL)
                created->next=NULL;
            else
                created->next=u[original->next];
            
            if(original->random==NULL)
                created->random=NULL;
            else
                created->random=u[original->random];
        }
        
        return u[head];
    }
};