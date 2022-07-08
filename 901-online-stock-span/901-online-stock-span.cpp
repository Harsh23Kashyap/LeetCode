class StockSpanner {
public:
    stack<int> s;
    vector<int> ans;
    int days=0;
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        //cout<<price<<endl;
        
        if(ans.size()==0)
        {
            ans.push_back(price);
            s.push(days);
            days++;
            return days;
        }
        while(!s.empty() and ans[s.top()]<=price)
        {
            s.pop();
            
        }
        ans.push_back(price);
        int x;
        if(s.empty())
        {
            
            x= days+1;
        }
        else
             x=days-s.top();
            
        //cout<<price<<" - "<<s.top()<<" "<<days<<endl;
        
        s.push(days);
        days++;
        
        return x;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */