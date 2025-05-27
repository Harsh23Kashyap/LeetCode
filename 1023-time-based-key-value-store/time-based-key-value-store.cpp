class TimeMap {
public:
    unordered_map<string, map<int, string>> u;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        u[key][timestamp]=value;
        
    }
    
    string get(string key, int ts) 
    {
        if(u.find(key)==u.end())
        return "";

        auto it=u[key].upper_bound(ts);
        cout<<it->first<<endl;
        if(it==u[key].begin()) return "";

        --it;
        return it->second;
        
    }
};