class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> u;
        int n=graph.size();
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                u[i].push_back(graph[i][j]);
            }
        }
        vector<int> col(n,-1);

        for(int i=0;i<n;i++){
            if(col[i]!=-1)
                continue;
            

            queue<int> q;
            q.push(i);
            col[i]=1;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int currcolor=col[it];

                for(auto ne:u[it]){
                    if(col[ne]!=-1 and col[ne]!=currcolor)
                    continue;
                    if(col[ne]==currcolor)
                    return false;
                    if(col[ne]==-1){
                        col[ne]=((currcolor==1)?2:1);
                        q.push(ne);
                    }
                }
            }
          
        }
          return true;
    }
};