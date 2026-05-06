class RandomizedSet 
{
public:

unordered_map<int,int> u;
vector<int> v;
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
        int idx=u[val];
        u[v.back()]=idx;
        v[idx]=v.back();
        v.pop_back();
        u.erase(val);
        return true;


    }
    
    int getRandom() {

        return v[rand()%v.size()];

        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */