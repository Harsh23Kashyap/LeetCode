class StockSpanner {
public:
    stack<int> s;
    vector<int> price;
    int days=0;
    StockSpanner() 
    {
        
    }
    
    int next(int p) 
    {
        int x=0;
        if(price.size()==0)
        {
            price.push_back(p);
            s.push(days);
            
            days++;
            return days;
        }
        else
        {
            //cout<<p<<" - ";
            price.push_back(p);
            while(!s.empty() and price[s.top()]<=p)
            {
                s.pop();
            }
            //cout<<s.size()<<endl;
            //cout<<price[s.top()]<<endl;
            if(s.empty())
                x= days+1;
            else
                x=days-s.top();
            
            s.push(days);
            days++;
            
        }
        return x;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */