class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> component;
        vector<bool> visited (n,false);
        
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)
                continue;
            visited[i]=true;
            int sz=0;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                sz++;
                
                int node=q.front();
                //cout<<node<<" ";
                q.pop();
                for(int j=0;j<adj[node].size();j++)
                {
                    if(visited[adj[node][j]]==false)
                    {
                        q.push(adj[node][j]);
                        visited[adj[node][j]]=true;
                    }
                    
                }
            }
            //cout<<endl;
            component.push_back(sz);
        }
        long long ans=0;
        long long count=0;
        for(int i=0;i<component.size();i++)
        {
            ans+=(component[i]*count);
            count+=component[i];
            
        }
        return ans;
            
        
    }
};