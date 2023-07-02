class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
class MyLinkedList {
public:
    Node* head=NULL;
    int l=0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(head==NULL or index>=l)
        {
            return -1;
        }
        
        Node* temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp->data;
        
    }
    
    void addAtHead(int val) {
        if(head==NULL)
        {
            head=new Node(val);
            l++;
            return;
        }
        l++;
        Node* n=new Node(val);
        n->next=head;
        head=n;
        
    }
    
    void addAtTail(int val) {
        if(l==0)
        {
            addAtHead(val);
            return;
        }
        l++;
        Node* prev;
        Node* temp=head;
        while(temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        
        prev->next=new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>l)
            return;
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(index==l)
        {
            addAtTail(val);
            return;
        }
        if(head==NULL)
            return;
        
        Node* temp=head;
        while(--index>0)
            temp=temp->next;
        l++;
        Node* t=new Node(val);
        t->next=temp->next;
        temp->next=t;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=l)
            return;
        if(index==0)
        {
            l--;
            head=head->next;
            return;
        }
        
        Node* temp=head;
        while(--index>0)
            temp=temp->next;
        temp->next=temp->next->next;
        l--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */