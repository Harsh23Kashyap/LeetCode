class NumberContainers {
public:
    unordered_map<int,set<int>> us;
    unordered_map<int,int> uf;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(uf.find(index)!=uf.end())
        {
            int valueis=uf[index];
            us[valueis].erase(index);
            if(us[valueis].size()==0){
                us.erase(valueis);
            }
        }
        uf[index]=number;
        us[number].insert(index);
    }
    
    int find(int number) {

        if(us.find(number)==us.end())
            return -1;
        return *(us[number].begin());

        

        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */