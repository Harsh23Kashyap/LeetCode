class RandomizedSet {
public:
    unordered_map<int,int> u;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(u.find(val)!=u.end())
            return false;
        
        v.push_back(val);
        u[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(u.find(val)==u.end())
            return false;
        
        int idx=u[val];
        v[idx]=v[v.size()-1];
        u[v[idx]]=idx;
        v.pop_back();
        u.erase(val);
        return true;
        
    }
    
    int getRandom() 
    {
        // for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
        //cout<<endl;
        int k=rand()%v.size();
        return v[k];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */