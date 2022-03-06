class MapSum {
public:
    unordered_map<string, int> m;
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) 
    {
        m[key]=val;
        
    }
    
    int sum(string prefix) 
    {
        int n=prefix.length();
        int sum=0;
        for(auto it:m)
        {
            string key=it.first;
            if(key.substr(0,n)==prefix)
            {
                sum+=it.second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */