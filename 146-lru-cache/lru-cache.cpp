class LRUCache {
public:
class Node{
    public:
    Node* left;
    Node* right;
    int key;
    int val;
    Node(int k, int c){
        key=k;
        val=c;
    }
};
int cap=0;
int sz=0;
unordered_map<int,Node*> u;
Node* start;
Node* end;

    LRUCache(int capacity) {
        cap=capacity;
        start= new Node(-1,-1);
        end= new Node(-1,-1);
        start->left=NULL;
        start->right=end;
        end->left=start;
        end->right=NULL;
    }
    
    int get(int key) {
        if(u.find(key)==u.end())
        return -1;
     Node* search=u[key];
     Node* leftavl=search->left;
     Node* rightavl=search->right;
     leftavl->right=rightavl;
     rightavl->left=leftavl;

     Node* afterstart=start->right;
     search->left=start;
     search->right=afterstart;
     start->right=search;
     afterstart->left=search;
     return search->val;

    }
    
    void put(int key, int value) {
            // If key exists, update value and move to front
        if (u.find(key) != u.end()) {
            Node* existing = u[key];
            existing->val = value;
            Node* leftavl=existing->left;
            Node* rightavl=existing->right;
            leftavl->right=rightavl;
            rightavl->left=leftavl;

            Node* afterstart=start->right;
            existing->left=start;
            existing->right=afterstart;
            start->right=existing;
            afterstart->left=existing;
            return;
        }
        Node * newnode=new Node(key,value);
         Node* afterstart=start->right;
        newnode->left=start;
        newnode->right=afterstart;
        start->right=newnode;
        afterstart->left=newnode;
        if(sz==cap){
            Node* beforelast=end->left;
            Node* beforebeforelast=beforelast->left;
            u.erase(beforelast->key);
            beforebeforelast->right=end;
            end->left=beforebeforelast;
            // del beforelast;

        }
        else sz++;

        u[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */