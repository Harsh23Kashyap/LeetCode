class LRUCache {
    public:
    class Node
    {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
           // next=prev=NULL;
        }
    };
    Node* head=new Node(-1,-1);
     Node* tail=new Node(-1,-1);
    int size;
    unordered_map<int,Node*> u;
    void insert(Node* curr)
    {
        Node* temp=head->next;
        temp->prev=curr;
        head->next=curr;
        curr->next=temp;
        curr->prev=head;
    }
    void del(Node* curr)
    {
        Node* delprev=curr->prev;
        Node* delnex=curr->next;
        delprev->next=delnex;
        delnex->prev=delprev;
    }
    LRUCache(int capacity) 
    {
        head->next=tail;
        tail->prev=head;
        size=capacity;
        
    }
    
    int get(int key) 
    {
        //cout<<key<<endl;
        if(u.find(key)==u.end())
            return -1;
        
       Node* curr=u[key];
        
        u.erase(key);
        
        del(curr);
        insert(curr);
        u[key]=head->next;
        //cout<<"success"<<endl;
        return curr->val;
    }
    
    void put(int key, int value) 
    {
        //cout<<key<<" and "<<value<<endl;
       if (u.find(key) != u.end()) 
       {
          Node* existingnode = u[key];
          u.erase(key);
          del(existingnode);
        }
        if (u.size() == size) 
        {
          u.erase(tail->prev->key);
          del(tail->prev);
        }

        insert(new Node(key, value));
        u[key] = head -> next;
       // cout<<"success"<<endl;

    }
};
