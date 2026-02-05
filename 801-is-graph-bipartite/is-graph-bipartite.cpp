class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);


        queue<int> q;
        // q.push(0);

        for(int i=0;i<n;i++){
            if(vis[i]!=-1){
                continue;

            }
            q.push(i);
            int col=0;
            vis[col]=0;

            while(!q.empty()){
                auto it=q.front();
                int mycol=vis[it];
                q.pop();
                for(auto ne:graph[it]){
                    
                    if(vis[ne]==-1){
                        vis[ne]=(mycol==0)?1:0;
                        q.push(ne);
                    }
                    else{
                        if(vis[ne]==mycol){
                            return false;;
                        }
                        
                    }
                }
            }
        }
        return true;
    }
};