class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> u;
        for(int i:arr)
            u[i]++;
        unordered_set<int> s;
        for(auto it:u)
        {
            if(s.find(it.second)!=s.end())
                return false;
            s.insert(it.second);
            
        }
        return true;
        
    }
};