class OrderedStream {
public:
    vector<string> ans;
    int i=0;
    OrderedStream(int n) 
    {
        ans.resize(n);
        
    }
    
    vector<string> insert(int id, string value) 
    {
        vector<string> res;
        
        id--;
        ans[id]=value;
        while(i<ans.size() and ans[i]!="")
        {
            res.push_back(ans[i]);
            i++;
        }
        return res;
        
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */