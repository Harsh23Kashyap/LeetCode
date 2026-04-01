class RandomizedSet {
public:
vector<int> v;
unordered_map<int,int> u;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(u.find(val)!=u.end())
        return false;
        v.push_back(val);
        
        u[val]=v.size()-1;

return true;
    }
    
    bool remove(int val) {
        if(u.find(val)==u.end())
        return false;
        if(u[val]==v.size()-1){
            u.erase(val);
            v.pop_back();
            return true;
        }

        int idx=u[val];
        int last=v.size()-1;
        
        v[idx]=v[last];
        u.erase(val);
        u[v[last]]=idx;
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        
        int n=v.size();
        int fl=rand()%n;

        return v[fl];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */