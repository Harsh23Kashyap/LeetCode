class Solution {
public:
    bool mColor(vector<vector<int>>& graph,unordered_map<int,int>& color)
    {
        queue<int> q;
        vector<bool> visited(graph.size(),false);
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==false)
            {
                color[i]=0;
                q.push(i);
                visited[i]=true;
                while(!q.empty())
                {
                    int curr=q.front();
                    cout<<"\n"<<"Curr-"<<curr<<endl;
                    q.pop();
                    int currColor=color[curr]==0?1:0;
                    for(int i=0;i<graph.size();i++)
                    {
                        if(graph[curr][i]==1)
                        {
                            if(!visited[i])
                            {
                                cout<<i<<" ";
                                q.push(i);
                                visited[i]=true;
                            }
                            if(color[i]==-1)
                            {
                                color[i]=currColor;

                            }
                            else if(color[i]!=currColor)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v=graph.size();
        vector<vector<int>> adj(v, vector<int> (v,0));
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int end=graph[i][j];
                adj[i][end]=1;
                
            }
        }
        
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        unordered_map<int,int> color;
        for(int i=0;i<v;i++)
            color[i]=-1;
        
        return mColor(adj,color);
        
        
    }
};