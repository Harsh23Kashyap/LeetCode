class CustomStack {
public:
    stack<int> s;
    int curr;
    int max;
    CustomStack(int maxSize) 
    {
        
        curr=0;
        max=maxSize;
    }
    
    void push(int x) 
    {
        if(curr<max)
        {
            curr++;
            s.push(x);
        }
        
    }
    
    int pop() 
    {
        if(curr==0)
            return -1;
        else
        {
            int x=s.top();
            curr--;
            s.pop();
            return x;
        }
    }
    
    void increment(int k, int val) 
    {
        stack<int> s2;
        while(!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty() and k-->0)
        {
            s.push(s2.top()+val);
            s2.pop();
        }
        while(!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */