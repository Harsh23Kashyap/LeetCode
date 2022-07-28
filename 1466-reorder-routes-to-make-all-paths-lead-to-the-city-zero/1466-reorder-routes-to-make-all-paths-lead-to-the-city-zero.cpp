class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        
        queue<int> dfs;
        vector<bool> visited(n,0);
        
        dfs.push(0);
        visited[0]=true;
       
        int c=0;
        while(!dfs.empty())
        {
            int curr=dfs.front();
            dfs.pop();
            
            //cout<<curr<<" ->";
            for(int j=0;j<adj[curr].size();j++)
            {

                int des=abs(adj[curr][j]);
                //cout<<des<<" - ";
                if(!visited[des])
                {
                    dfs.push(des);
                    visited[des]=true;
                    if(adj[curr][j]>0)
                        c++;
                }
            }
            //cout<<endl;
        }
        // for(bool v:visited)
        //     cout<<v<<endl;
        
        return c;
        
    }
};