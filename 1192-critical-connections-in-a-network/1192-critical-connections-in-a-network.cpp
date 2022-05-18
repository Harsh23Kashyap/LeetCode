class Solution {
public:
    int time=1;
    void dfs(int parent, int child, unordered_map<int,vector<int>>& adj,vector<vector<int>>& ans,unordered_map<int,pair<int,int>>& times)
    {
        times[child]={time,time};
        time++;
        for(int i=0;i<adj[child].size();i++)
        {
            int curr=adj[child][i];
            if(curr==parent)
                continue;
            
            if(times.find(curr)==times.end())
            {
                dfs(child,curr,adj,ans,times);
                times[child].second=min(times[child].second,times[curr].second);
                if(times[curr].second>times[child].first)
                {
                    ans.push_back({child,curr});
                }
            }
            else
            {
                times[child].second = min(times[child].second,times[curr].first);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> adj;
        unordered_map<int,pair<int,int>> times;
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
       dfs(-1,0,adj,ans,times);
        return ans;
    }
};