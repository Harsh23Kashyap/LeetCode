class LRUCache {
public:
    class Node
    {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k,int v)
        {
            this->key=k;
            this->val=v;
        }
    };
    
    
    
    void add(Node* curr)
    {
        Node* temp=head->next;
        curr->next=temp;
        temp->prev=curr;
        head->next=curr;
        curr->prev=head;
    }
    void del(Node* curr)
    {
        Node* delprev=curr->prev;
        Node* delnext=curr->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> u;
    int size;
    LRUCache(int capacity) 
    {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) 
    {
        if(u.find(key)==u.end())
            return -1;
        
        Node* curr=u[key];
        u.erase(key);
        del(curr);
        add(curr);
        u[key]=head->next;
        return curr->val;
        
    }
    
    void put(int key, int value) 
    {
        if(u.find(key)!=u.end())
        {
            Node* curr=u[key];
            del(curr);
            u.erase(key);
        }
        else if(u.size()==size)
        {
            Node* d=tail->prev;
            u.erase(d->key);
            del(d);
        }
        add(new Node(key,value));
        u[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */