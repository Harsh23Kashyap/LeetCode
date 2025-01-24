class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> u;
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                u[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto it=q.front();
            ans.push_back(it);
            // cout<<it<<endl;
            q.pop();
            for(int i:u[it])
            {
                if(--indegree[i]==0)
                    q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};