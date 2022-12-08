class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) 
    {
        unordered_map<int,vector<int>> u;
        
        for(int i=0;i<gs.size();i++)
            u[gs[i]].push_back(i);
        
        vector<vector<int>> ans;
        for(auto it:u)
        {
            int size=it.first;
            vector<int> temp=it.second;
            
            vector<int> res;
            for(int i=0;i<temp.size();i++)
            {
                res.push_back(temp[i]);
                if((i+1)%size==0)
                {
                    ans.push_back(res);
                    res.clear();
                }
            }
            
        }
        return ans;
        
    }
};