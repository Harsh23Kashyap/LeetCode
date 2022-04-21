class Node
{
public:
    int key;
    Node* next;
    Node()
    {
        next = NULL;
    }
    Node(int key)
    {
        this->key = key;
        next = NULL;
    }
};

class MyHashSet 
{
public:
    Node *head;
    MyHashSet() 
    {
        head=new Node();
    }
    
    void add(int key) 
    {
        if(contains(key))
            return;
        Node* temp = new Node(key);   
        temp->next=head;
        head=temp; 
    }
    
    void remove(int key) 
    {
        Node* temp = head;
        Node* prev=NULL;
        if(head->key==key)
        {
            head=head->next;
            return;
        }
        while(temp!=NULL)
        {
            if(temp->key == key)
            {
                cout<<temp->next;
                prev->next = temp->next;
                return;
            }
            prev= temp;
            temp= temp->next;
        }
        
    }
    
    bool contains(int key) 
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->key == key)
                return true;
            temp = temp->next;
        
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */