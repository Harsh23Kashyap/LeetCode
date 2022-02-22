class Node
{
public:
    int key;
    int value;
    Node* next;
    Node()
    {
        next = NULL;
    }
    Node(int key,int value)
    {
        this->key = key;
        this->value  = value;
        next =NULL;
    }
};

class MyHashMap 
{
    Node* head;
public:
    MyHashMap() 
    {
        head =new Node();
    }
    
    void put(int key, int value) 
    {
        Node* temp = head;
        Node* prev=NULL;
        int flag=0;
        
        if(head==NULL)
        {
            Node* add = new Node(key,value);
            head=add;
            return ;
        }
        
        while(temp)
        {
            if(temp->key == key)
            {
                temp->value = value;
                return;
            }
            prev= temp;
            temp= temp->next;
        }
        prev->next = new Node(key,value);    
    }
    
    int get(int key) 
    {
        
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->key == key)
                return temp->value;
            temp = temp->next;
        
        }
        return -1;
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
                prev->next = temp->next;
                return;
            }
            prev= temp;
            temp= temp->next;
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */