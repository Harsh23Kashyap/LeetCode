class LRUCache {
public:
    class Node{ 
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v)
        {
            key=k,
            val=v;
            next=NULL;
            prev=NULL;
        }    
};
int sz=0;
int c=0;
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);

unordered_map<int, Node*> u;
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        c=capacity;
    }
    void deleteNode(Node* a){
         Node* pprev=a->prev;
         Node* pnext=a->next;
         pnext->prev=pprev;
         pprev->next=pnext;

         u.erase(a->key);
         delete(a);
    }
    void insert(int key, Node* curr){
        Node* chead=head;
         Node* pnext=chead->next;
         curr->prev=head;
         curr->next=pnext;
         pnext->prev=curr;
         head->next=curr;
    }
    int get(int key) {

        if(u.find(key)==u.end())
            return -1;
        
        Node* curr=u[key];

        int val=curr->val;

        deleteNode(curr);

        curr=new Node(key,val);
        u[key]=curr;

        insert(key,curr);
        return val;
        
    }
    
    void put(int key, int value) {
        if(u.find(key)!=u.end())
        {
            deleteNode(u[key]);
            sz--;
        }
        Node* curr=new Node(key,value);
        u[key]=curr;

        insert(key,curr);
        
        sz++;
        if(sz>c){
            sz--;
            Node* last=tail->prev;
            deleteNode(last);
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */