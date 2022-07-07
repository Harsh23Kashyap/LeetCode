#define ll long long
class MinStack {
public:
    stack<ll> st;
    ll mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int v) 
    {
        ll val=(ll)v;
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else
        {
            if(val<mini)
            {
                st.push(2*val*1ll-mini);
                mini=val;
               
            }
            else
                st.push(val);
        }
        
    }
    
    void pop() 
    {
        if(st.empty())
            return ;
        if(st.top()<mini)
        {
            mini=2*mini-st.top();
            
        }
         st.pop();
        
        
    }
    
    int top() {
        if(st.top()<mini)
            return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */