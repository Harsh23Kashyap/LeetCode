class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        unordered_map<int,unordered_set<int>> u;
        
        for(int i=0;i<logs.size();i++)
        {
            int user=logs[i][0],min=logs[i][1];
            u[user].insert(min);
        }
        
        vector<int> arr(k,0);
        
        for(auto it:u)
            arr[it.second.size()-1]++;
        
        
        
        return arr;
        
        
    }
};