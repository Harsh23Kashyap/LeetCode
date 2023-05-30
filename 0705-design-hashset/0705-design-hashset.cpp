class MyHashSet {
public:
    unordered_set<int> u;
    MyHashSet() {
        
    }
    
    void add(int key) {
        u.insert(key);
    }
    
    void remove(int key) {
         if(u.find(key)!=u.end())
            u.erase(u.find(key));
    }
    
    bool contains(int key) {
        if(u.find(key)!=u.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */