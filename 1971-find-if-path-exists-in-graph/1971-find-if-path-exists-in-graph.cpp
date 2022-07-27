class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int s=edges[i][0];
            int d=edges[i][1];
            //cout<<s<<" "<<d<<endl;
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        
        cout<<1<<endl;
        queue<int> q;
        vector<bool> vis(adj.size(),false);
        q.push(source);
        vis[source]=true;
        while(!q.empty())
        {
            int curr=q.front();
            //cout<<curr<<endl;
            q.pop();
            if(curr==destination)
                return true;
            for(int j=0;j<adj[curr].size();j++)
            {
                int dest=adj[curr][j];
                if(!vis[dest])
                {
                    q.push(dest);
                    vis[dest]=true;
                }
            } 
        }
        return false;
        
    }
};