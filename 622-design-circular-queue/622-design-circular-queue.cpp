class MyCircularQueue {
public:
    vector<int> v;
    int size;
    int front=0,back=0;
    MyCircularQueue(int k) 
    {
        for(int i=0;i<k;i++)
        {
            v.push_back(0);
        }
        size=k;
        
    }
    
    bool enQueue(int value) 
    {
        if(isFull())
            return false;
        
        //cout<<front<<"-"<<value<<endl;
        v[front%size]=value;
        front++;
        return true;
        
    }
    
    bool deQueue() 
    {
        if(isEmpty())
            return false;
        

        v[back%size]=-1;
        back++;
        return true;
        
    }
    
    int Front() 
    {
        if(isEmpty())
            return -1;
        return v[back%size];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return v[(front-1)%size];
    }
    
    bool isEmpty() 
    {
        return abs(front-back)==0;
        
    }
    
    bool isFull() {
        return abs(front-back)==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */